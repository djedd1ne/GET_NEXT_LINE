/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:52:45 by djmekki           #+#    #+#             */
/*   Updated: 2022/06/22 21:11:03 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

size_t	ft_strlen(const char *s);
long	ft_linelen(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_readline(int fd, char *buffer, char *tmp, char **str);
int		ft_isline(char *str);
char	*ft_save(char *str);

#endif
