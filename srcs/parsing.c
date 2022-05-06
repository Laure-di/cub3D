/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:55:50 by majacque          #+#    #+#             */
/*   Updated: 2022/04/30 17:29:58 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

void	clear_map(char ***map, int height)
{
	int	i;

	if (!*map)
		return ;
	i = 0;
	while (i < height)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

int	parsing(t_data *data, char const *const filename)
{
	int	fd;
	int	nb_line_map;

	if (check_extension(filename, ".cub"))
		return (error_parsing("Wrong file extension, should be <file>.cub"));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_parsing("Open failed"));
	if (get_textures(data, fd, &nb_line_map) || get_infos_map(data, fd, &nb_line_map))
	{
		close(fd);
		return (1);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_parsing("Open failed"));
	if (get_map(data, fd, nb_line_map))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (check_map(&data->map))
		return (1);
	data->player = initialize_player(data->map);
	data->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	return (0);
}
