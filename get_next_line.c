/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oovsiann <oovsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:25:30 by oovsiann          #+#    #+#             */
/*   Updated: 2024/09/30 20:28:44 by oovsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Return the position of the character 'c' or -1 if there is no character
ssize_t	ft_find_next(char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// Read from fd until find a '\n' or end of file. Join this reading in 'storage'
char	*ft_fill_storage(int fd, char *storage)
{
	ssize_t	bytesread;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(storage), NULL);
	bytesread = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);
	while (bytesread != 0 && ft_find_next(storage, '\n') < 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

// Return from storage until a \n or the end of the string
char	*ft_get_line(char *storage)
{
	char	*line;
	size_t	line_len;

	line_len = 0;
	if (!storage)
		return (NULL);
	while (storage[line_len] != '\n' && storage[line_len] != '\0')
	{
		line_len++;
	}
	if (line_len == 0 && storage[line_len] == '\0')
		return (NULL);
	if (storage[line_len] == '\n')
		line_len++;
	line = malloc(line_len + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, storage, line_len);
	line[line_len] = '\0';
	return (line);
}

// Return the rest of storage after a '\n' or '\0'
char	*ft_save_the_rest(char *storage)
{
	unsigned int	start;

	if (!storage)
		return (free(storage), NULL);
	start = ft_find_next(storage, '\n') + 1;
	if (start == 0)
	{
		free(storage);
		return (NULL);
	}
	storage = ft_substr(storage, start, ft_strlen(storage) - start);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage;
	char			*line;

	if (storage == NULL)
	{
		storage = malloc(1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	storage = ft_fill_storage(fd, storage);
	if (!storage)
		return (free(storage), NULL);
	line = ft_get_line(storage);
	storage = ft_save_the_rest(storage);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	fd = open("Himno_al_Amor.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("[%d]:%s", count, line);
		if (line == NULL)
			break ;
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
