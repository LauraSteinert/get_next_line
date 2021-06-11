/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:09:58 by lsteiner          #+#    #+#             */
/*   Updated: 2021/06/11 12:09:58 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	search;
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	search = (unsigned char)c;
	if (*s_cpy == search)
		return ((char *)s);
	while (*s_cpy++)
	{
		if (*s_cpy == search)
			return ((char *)s_cpy);
	}
	return (NULL);
}

char	*ft_double_the_line(char *save, size_t size)
{
	char	*duplicate;
	size_t	i;

	duplicate = malloc(size + 1);
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		duplicate[i] = save[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
