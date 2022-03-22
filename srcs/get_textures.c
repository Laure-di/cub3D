/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:10:52 by majacque          #+#    #+#             */
/*   Updated: 2022/03/22 19:13:40 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

static bool	__is_valid_identifier(char *line)
{
	if (ft_strncmp(line, "NO", 2) && ft_strncmp(line, "SO", 2)
		&& ft_strncmp(line, "EA", 2) && ft_strncmp(line, "WE", 2)
		&& ft_strncmp(line, "F ", 2) && ft_strncmp(line, "C ", 2))
	{
		ft_putstr_fd("Error\nWrong texture identifier: ", STDERR_FILENO);
		ft_putendl_fd(line, STDERR_FILENO);
		return (false);
	}
	return (true);
}

static int	__set_texture(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (g_texture_lookup[i].id)
	{
		if (!ft_strncmp(line, g_texture_lookup[i].id, 2))
		{
			if (g_texture_lookup[i].f(data, line))
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static bool	__is_all_textures_set(t_texture *textures)
{
	if (!textures->ceiling_color || !textures->floor_color)
		return (false);
	else if (!textures->north.ptr || !textures->south.ptr
		|| !textures->east.ptr || !textures->west.ptr)
		return (false);
	return (true);
}

int	get_textures(t_data *data, int const fd, int *const nb_line_map)
{
	char	*line;
	int		ret;

	line = NULL;
	*nb_line_map = 0;
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (error_parsing("Get_next_line failed"));
	while (ret == 1)
	{
		(*nb_line_map)++;
		if (!*line && __is_all_textures_set(&data->textures))
			break ;
		else if (!__is_valid_identifier(line) || __set_texture(data, line))
		{
			free(line);
			return (1);
		}
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	if (ret == -1)
		return (error_parsing("Get_next_line failed"));
	return (0);
}
