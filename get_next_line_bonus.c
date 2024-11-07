/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oovsiann <oovsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:23:57 by oovsiann          #+#    #+#             */
/*   Updated: 2024/09/30 20:30:25 by oovsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Return the position of the character 'c' or -1 if there is no character
ssize_t	ft_find_next(char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i])
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
		return (NULL);
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

	if (storage == NULL)
		return (NULL);
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
	static char		*storage[1024];
	char			*line;

	if (storage[fd] == NULL)
	{
		storage[fd] = malloc(1);
		if (!storage[fd])
			return (NULL);
		storage[fd][0] = '\0';
	}
	storage[fd] = ft_fill_storage(fd, storage[fd]);
	if (!storage[fd])
		return (free(storage[fd]), NULL);
	line = ft_get_line(storage[fd]);
	storage[fd] = ft_save_the_rest(storage[fd]);
	return (line);
}

/*int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;
	int		i;

	i = 1;
	fd1 = open("test1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		printf("Error opening file\n");
		//return (1);
	}
	fd2 = open("test2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		printf("Error opening file\n");
		//return (1);
	}
	fd3 = open("test3.txt", O_RDONLY);
	if (fd3 == -1)
	{
		printf("Error opening file\n");
		//return (1);
	}
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (line1 != NULL || line2 != NULL || line3 != NULL)
	{
		if (line1 != NULL)
			printf("%d.: %s", i, line1);
		else
			printf("%d.:\n", i);
		free(line1);
		line1 = get_next_line(fd1);
		if (line2 != NULL)
			printf("%d.: %s", i, line2);
		else
			printf("%d.:\n", i);
		free(line2);
		line2 = get_next_line(fd2);
		if (line3 != NULL)
			printf("%d.: %s", i, line3);
		else
			printf("%d.:\n", i);
		free(line3);
		line3 = get_next_line(fd3);
		i++;
	}
	//free(line1);
	//free(line2);
	//free(line3);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
