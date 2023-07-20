/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:23:26 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/20 12:33:12 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			*(buffer + j++) = *(buffer + i++);
		while (*(buffer + j))
			*(buffer + j++) = '\0';
	}
	else
	{
		while (i < BUFFER_SIZE)
		*(buffer + i++) = '\0';
	}
}

char	*create_line(char *temp)
{
	char	*line;
	int		i;
	int		nl;

	i = 0;
	nl = 1;
	if (!temp)
		return (NULL);
	if (ft_strchr(temp, '\n'))
		nl = 2;
	while (*(temp + i) && *(temp + i) != '\n')
		i++;
	line = ft_calloc(i + nl, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*(temp + i) && *(temp + i) != '\n')
	{
		*(line + i) = *(temp + i);
		i++;
	}
	if (nl == 2)
		*(line + i) = '\n';
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int		rchars;

	temp = NULL;
	if (*buffer)
	{
		temp = create_line(buffer);
		if (ft_strchr(temp, '\n'))
			return (temp);
		manage_buffer(buffer);
	}
	rchars = read(fd, buffer, BUFFER_SIZE);
	while (rchars > 0)
	{
		if (!temp)
			temp = ft_calloc(BUFFER_SIZE + 1, 1);
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break ;
		manage_buffer(buffer);
		rchars = read(fd, buffer, BUFFER_SIZE);
	}
	if (rchars < 0)
	{
		free (temp);
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_line(fd, buffer);
	if (!temp)
		return (NULL);
	line = create_line(temp);
	if (!line)
		return (NULL);
	manage_buffer(buffer);
	if (temp)
		free (temp);
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		printf("Read: %s\n", buffer);
		free(buffer);
	}

}*/
