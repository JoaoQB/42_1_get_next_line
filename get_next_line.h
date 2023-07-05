/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:55:54 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/05 17:07:44 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // Memory allocation
# include <stdarg.h> // va_lists
# include <string.h> // String manipulation
# include <stddef.h> // Types and macros like NULL and size_t
# include <stdio.h> // Printf
# include <unistd.h> // System calls, write
# include <limits.h> // Limits, for testing
# include <fcntl.h> // Open function

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

# endif

char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
