/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:35:09 by djmekki           #+#    #+#             */
/*   Updated: 2022/06/22 21:14:09 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfile(int fd, char *buffer, char *tmp, char **str)
{
	int		bytes_size;

	bytes_size = 1;
	while (bytes_size != 0)
	{
		bytes_size = read(fd, buffer, BUFFER_SIZE);
		if (bytes_size == -1)
			return (NULL);
		buffer[bytes_size] = 0;
		tmp = *str;
		if (!tmp)
		{
			tmp = (char *)malloc(sizeof(char) * 1);
			if (!tmp)
				return (NULL);
			tmp[0] = 0;
		}
		*str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_isline(*str))
			bytes_size = 0;
	}
	free(buffer);
	return (*str);
}

char	*ft_getline(char *str)
{
	int		i;
	char	*line;

	if (!str)
		return (NULL);
	if (*str == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (ft_linelen(str) + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == 0)
		line[i] = 0;
	else if (str[i] == '\n')
	{
		line[i++] = '\n';
		line [i] = 0;
	}
	return (line);
}

char	*ft_save(char *str)
{
	char	*saved;
	int		j;
	int		i;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == 0)
	{
		free(str);
		return (NULL);
	}
	saved = (char *)malloc(sizeof(char) * (i - j));
	if (!saved)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		saved[i++] = str[j++];
	saved[i] = 0;
	free(str);
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str[1024];
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ft_readfile(fd, buffer, tmp, &str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_getline(str[fd]);
	str[fd] = ft_save(str[fd]);
	return (line);
}
