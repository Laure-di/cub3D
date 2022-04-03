/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:23:56 by majacque          #+#    #+#             */
/*   Updated: 2022/04/03 14:48:06 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

static int	__goto_line_map(int const fd, int line_map)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret == 1 && line_map-- > 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	free(line);
	if (ret == -1)
		return (1);
	return (0);
}

static int	__calloc_map(t_data *data)
{
	int	i;

	data->map.matrix = ft_calloc(data->map.height, sizeof(char *));
	if (!data->map.matrix)
		return (1);
	i = 0;
	while (i < data->map.height)
	{
		data->map.matrix[i] = ft_calloc(data->map.widht, sizeof(char));
		if (!data->map.matrix[i])
		{
			clear_map(data->map.matrix, data->map.height);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	__fill_with_spaces(char *const line_map, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line_map[i] == 0)
			line_map[i] = ' ';
		i++;
	}
}

static int	__fill_matrix(t_data *data, int const fd)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	ret = get_next_line(fd, &line);
	i = 0;
	while (ret == 1)
	{
		if (i >= data->map.height)
			return (error_parsing("The map should be the last element"));
		ft_strcpy(data->map.matrix[i], line);
		if ((int)ft_strlen(line) < data->map.widht)
			__fill_with_spaces(data->map.matrix[i], data->map.widht);
		i++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
		return (error_parsing("Get_next_line failed"));
	return (0);
}

int	get_map(t_data *data, int const fd, int line_map)
{
	if (data->map.height == 0)
		return (error_parsing("Missing map"));
	else if (data->map.height < 3 || data->map.widht < 3)
		return (error_parsing("The map is too small"));
	if (__goto_line_map(fd, line_map))
		return (error_parsing("Get_next_line failed"));
	if (__calloc_map(data))
		return (error_parsing("Malloc failed"));
	if (__fill_matrix(data, fd))
		return (1);
	return (0);
}
