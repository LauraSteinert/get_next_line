/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:32:42 by lsteiner          #+#    #+#             */
/*   Updated: 2021/06/07 20:32:42 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_to_kill_a_static_variable(char **save)
{
	if (*save != NULL)
	{
		free(*save);
		*save = NULL;
	}
}

static int	ft_find_new_line(char *line)
{
	int	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\n')
			break ;
		len++;
	}
	return (len);
}

static int	ft_making_line(char **save, char **line)
{
	int		size_line;
	char	*temp;

	size_line = ft_find_new_line(*save);
	if ((*save)[size_line] == '\0')
	{
		*line = ft_strdup(*save);
		ft_to_kill_a_static_variable(save);
		return (0);
	}
	*line = ft_double_the_line(*save, size_line);
	temp = ft_strdup((*save) + size_line + 1);
	free(*save);
	*save = temp;
	return (1);
}

static int	ft_return(char **save, char **line, ssize_t size_read)
{
	if (size_read < 0)
		return (-1);
	else if (size_read == 0 && *save == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_making_line(save, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	ssize_t		size_read;
	char		*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	size_read = read(fd, buffer, BUFFER_SIZE);
	while (size_read > 0)
	{
		buffer[size_read] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(save, buffer);
			free(save);
			save = temp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		size_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_return(&save, line, size_read));
}
