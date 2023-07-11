/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:23:31 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/11 20:35:15 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	manage_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strchr(buffer, '\n'))
	{
		while (*(buffer + i) != '\n')
			i++;
		i++;
		while (*(buffer + i))
		{
			*(buffer + j) = *(buffer + i);
			*(buffer + i) = '\0';
			i++;
			j++;
		}
		while (*(buffer + j))
		{
			*(buffer + j) = '\0';
			j++;
		}
	}
	else
	{
		while (*(buffer + i))
		{
			*(buffer + i) = '\0';
			i++;
		}
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		if (s2[j] == '\n')
		{
			dest[i] = '\n';
			i++;
			break ;
		}
		dest[i++] = s2[j];
	}
	*(dest + i) = '\0';
	free (s1);
	return (dest);
}

/*char	*create_line(char *buffer, char *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	temp = malloc((ft_strlen(temp) + BUFFER_SIZE + 1) * sizeof(char));
	while (*(temp + j))
		j++;
	while (*(buffer + i))
	{
		*(temp + j) = *(buffer + i);
		i++;
		j++;
		if (*(buffer + i) == '\n')
		{
			*(temp + j) = '\n';
			j++;
			break ;
		}
	}
	*(temp + j) = '\0';
	return (temp);
}*/

char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int		rchars;

	temp = NULL;
	if (*buffer)
	{
		temp = malloc((ft_strlen(buffer) + 1) * sizeof(char));
		temp = ft_strjoin(temp, buffer);
	}
	rchars = read(fd, buffer, BUFFER_SIZE);
	if (rchars <= 0)
		return (NULL);
	while (rchars > 0)
	{
		if (!temp)
			temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break ;
		rchars = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}
