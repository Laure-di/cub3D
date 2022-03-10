/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:00:53 by majacque          #+#    #+#             */
/*   Updated: 2021/11/19 05:33:10 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_init(int fd, char *buffer, char **content, int *ret)
{
	*ret = 1;
	if (!*buffer)
	{
		*ret = read(fd, buffer, BUFFER_SIZE);
		if (*ret == -1)
			return (-1);
		buffer[*ret] = 0;
	}
	*content = ft_strdup(buffer);
	return (*ret);
}

static char	*ft_get_line(char *content)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = content[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static int	ft_save_rest(char *buffer, char *content)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
	{
		i++;
		check++;
	}
	while (content[i])
		buffer[j++] = content[i++];
	buffer[j] = 0;
	return (check);
}

static int	ft_make_line(int fd, char *buffer, char **content)
{
	char	*tmp;
	int		ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
	{
		free(*content);
		return (-1);
	}
	buffer[ret] = 0;
	tmp = ft_strdup(*content);
	free(*content);
	if (!tmp)
		return (-1);
	*content = ft_strjoin(tmp, buffer);
	free(tmp);
	if (!*content)
		return (-1);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1] = {};
	char		*content;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (ft_init(fd, buffer, &content, &ret) == -1)
		return (-1);
	while (!ft_strchr(content, '\n') && ret)
	{
		ret = ft_make_line(fd, buffer, &content);
		if (ret == -1)
			return (-1);
	}
	*line = ft_get_line(content);
	if (!*line)
	{
		free(content);
		return (-1);
	}
	ret = ft_save_rest(buffer, content);
	free(content);
	if (!ret)
		return (0);
	return (1);
}
