/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:31:04 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/11 16:31:51 by jqueijo-         ###   ########.fr       */
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

char	*get_next_line(int fd);

# endif
