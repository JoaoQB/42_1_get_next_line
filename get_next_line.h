/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:47:26 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/12 21:54:02 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>// Memory allocation
# include <stdarg.h>// va_lists
# include <string.h>// String manipulation
# include <stddef.h>// Types and macros like NULL and size_t
# include <stdio.h>// Printf
# include <unistd.h>// System calls, write
# include <limits.h>// Limits, for testing
# include <fcntl.h>// Open function

void	clean_buffer(char *buffer);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	manage_buffer(char *buffer);
char	*create_line(char *temp);
char	*read_line(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
