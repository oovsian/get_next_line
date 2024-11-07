/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oovsiann <oovsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:29:01 by oovsiann          #+#    #+#             */
/*   Updated: 2024/09/12 19:46:35 by oovsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>//for open
# include <unistd.h>//for read, write
# include <stddef.h>//for size_t
# include <sys/types.h>//for ssize_t
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

size_t			ft_strlen(char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strdup(char *s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_save_the_rest(char *storage);
char			*ft_get_line(char *storage);
char			*ft_fill_storage(int fd, char *storage);
ssize_t			ft_find_next(char *s, int c);

#endif
//size_t to count bytes
//ssize_t to count bytes and indicate errors