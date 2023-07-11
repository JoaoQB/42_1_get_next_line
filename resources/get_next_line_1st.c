/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_1st.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:55:51 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/11 16:23:10 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_1st.h"

/*char	*manage_buffer(char *buffer)
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
		line = ft_calloc(((ft_strlen(buffer) - i)), 1);
		i++;
		while (*(buffer + i) && *(buffer + i) != '\0')
			*(line + j++) = *(buffer + i++);
	}
	else
		line = ft_calloc(BUFFER_SIZE + 1, 1);
	free (buffer);
	return (line);
}*/

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
		while (*(buffer + i) != '\0')
		{
			*(buffer + j) = *(buffer + i);
			*(buffer + i) = '\0';
			i++;
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

char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int		rchars;

	temp = NULL;
	if (*buffer)
	{
		temp = ft_strjoin(buffer, temp);
		printf("This is temp: %s\n", temp);
	}
	rchars = read(fd, buffer, BUFFER_SIZE);
	if (rchars <= 0)
		return (NULL);
	while (rchars > 0)
	{
		if (!temp)
			temp = ft_calloc(BUFFER_SIZE, 1);
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break ;
		rchars = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}

char	*create_line(char *temp)
{
	char	*line;
	int		i;

	i = 0;
	if (temp && !*(temp + i))
		return (NULL);
	while (*(temp + i) && *(temp + i) != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (*(temp + i) && *(temp + i) != '\n')
	{
		*(line + i) = *(temp + i);
		i++;
	}
	if (*(temp + i) && *(temp + i) == '\n')
		*(line + i) = '\n';
	free (temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = read_line(fd, buffer);
	if (!temp)
		return (NULL);
	line = create_line(temp);
	if (!line)
		return (NULL);
	manage_buffer(buffer);
	printf("This is buffer: %s\n", buffer);
	return (line);
}

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
	}

}
