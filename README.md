<br />
<div align="center">
  <a href="https://github.com/djedd1ne/GET_NEXT_LINE">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>
  <h3 align="center">GET_NEXT_LINE</h3>
</div>
<br><br>

$\color[RGB]{186,71,71}DESCRIPTION:$<br>
&emsp;Using only one static variable, This function take a file descriptor as a parameter (file or standard input). Successive calls of the function allow you to
read the entire text file referenced by the file descriptor, one line at a time. This is not a recreation of getline().<br>
&emsp; $\color[RGB]{186,71,71}char*\ get\textunderscore next\textunderscore line(int$ $\color[RGB]{87,150,87}fd$ $\color[RGB]{186,71,71})$<br>
&emsp; $\color[RGB]{87,150,87}fd$: file descriptor<br><br>
$\color[RGB]{186,71,71}BONUS:$<br>
&emsp;Handle multiple file descriptors simultaneously.<br><br>

$\color[RGB]{186,71,71}RETURN\ VALUE:$<br>
&emsp;returns one line at the time<br>
&emsp;returns ```NULL``` if nothing to read or an error has occured<br>

$\color[RGB]{186,71,71}TEST$<br>
&emsp;Create a file
```bash
touch file
```
&emsp;Create a main.c and use the code below:
```C
int main() 
{
	int fd;
	char *next_line;
	int count;

	fd = open("file", O_RDONLY);
	if (fd < 0)
		return 1;
	count = 0;
	next_line = get_next_line(fd);
	count++;
	printf("%d:\t%s\n", count, next_line);
	next_line = NULL;
	close (fd);

	return(0);
}
```

