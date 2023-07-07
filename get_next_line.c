/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:55:51 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/07 11:34:52 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*manage_buffer(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strchr(buffer, '\n'))
	{
		while (*(buffer + i) != '\n')
			i++;
		line = ft_calloc((ft_strlen(buffer) - i) + 1, 1);
		i++;
		while (*(buffer + i) && *(buffer + i) != '\0')
		{
			*(line + j) = *(buffer + i);
			j++;
			i++;
		}
	}
	else
		line = ft_calloc(1, 1);
	free (buffer);
	return (line);
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
	buffer = manage_buffer(buffer);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("file2.txt", O_RDONLY);
	char	*buffer;
	char	*s2;
	char	*s3;
	char	*s4;

	buffer = get_next_line(fd);
	s2 = get_next_line(fd);
	s3 = get_next_line(fd);
	s4 = get_next_line(fd);
	printf("I have read: \n%s", buffer);
	printf("I have read: \n%s", s2);
	printf("I have read: \n%s", s3);
	printf("I have read: \n%s", s4);
	buffer = get_next_line(fd);
	s2 = get_next_line(fd);
	s3 = get_next_line(fd);
	s4 = get_next_line(fd);
	printf("I have read: \n%s$", buffer);
	printf("I have read: \n%s$", s2);
	printf("I have read: \n%s$", s3);
	printf("I have read: \n%s$", s4);
}
