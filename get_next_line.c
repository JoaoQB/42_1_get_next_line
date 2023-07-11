/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:23:26 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/11 20:43:51 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Manage buffer inside create line function. */

#include "get_next_line.h"

char	*create_line(char *temp)
{
	char	*line;
	int		i;

	i = 0;
	while (*(temp + i) && *(temp + i) != '\n')
		i++;
	line = malloc(i * sizeof(char));
	i = 0;
	while (*(temp + i) && *(temp + i) != '\n')
	{
		*(line + i) = *(temp + i);
		i++;
	}
	if (*(temp + i) && *(temp + i) == '\n')
		*(line + i) = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*temp;
//	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = read_line(fd, buffer);
	if (!temp)
		return (NULL);
//	line = create_line(temp);
//	if (!line)
//		return (NULL);
	manage_buffer(buffer);
//	free(temp);
	return (temp);
}

/*int	main(void)
{
	int	fd;

	fd = open("file2.txt", O_RDONLY);
	char	*buffer;

	buffer = get_next_line(fd);
	printf("Read: %s", buffer);
	buffer = get_next_line(fd);
	printf("Read: %s", buffer);
	buffer = get_next_line(fd);
	printf("Read: %s", buffer);
	free(buffer);
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
	free(buffer);

}
*/
