/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oovsiann <oovsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:08:56 by oovsiann          #+#    #+#             */
/*   Updated: 2024/09/23 12:58:22 by oovsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	i = 0;
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(s);
	ptr = malloc(len + 1);
	i = 0;
	if (ptr == NULL || s == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (free(res), NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (free(res), NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	free(s);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new_s;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = 0;
	if (!new_s)
		return (NULL);
	while (i < s1_len)
	{
		new_s[i] = s1[i];
		i++;
	}
	while (i < (s1_len + s2_len + 1) - 1)
	{
		new_s[i] = *s2++;
		i++;
	}
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}
