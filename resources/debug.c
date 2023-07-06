/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:25:33 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/05 21:46:39 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, size * nmemb);
	return (tmp);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
		dest[i++] = s2[j];
	*(dest + i) = '\0';
	return (dest);
}
char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int	rchars;

	temp = ft_calloc((BUFFER_SIZE + 1), 1);
	rchars = read(fd, temp, BUFFER_SIZE);
	while (rchars > 0)
	{
		if (!buffer)
			buffer = ft_calloc(BUFFER_SIZE, 1);
		buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break;
		rchars = read(fd, temp, BUFFER_SIZE);
	}
	free (temp);
	return (buffer);
}

char	*create_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (*(buffer + i) != '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	i = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
	{
		*(line + i) = *(buffer + i);
		i++;
	}
	if (*(buffer + i) && *(buffer + i) == '\n')
		*(line + i) = '\n';
	return (line);

}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	line = create_line(buffer);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("file2.txt", O_RDONLY);
	char	*buffer;
	char	*s2;

	buffer = get_next_line(fd);
	s2 = get_next_line(fd);
	printf("I have read: \n%s$\n", buffer);
	printf("I have read: \n%s$\n", s2);
}
