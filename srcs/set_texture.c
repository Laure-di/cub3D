/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:21:47 by majacque          #+#    #+#             */
/*   Updated: 2022/03/15 14:37:07 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	set_north(t_data *data, char *line)
{
	// TODO set_north()
	int	i;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || check_extension(&line[i], ".xpm"))
		return (1); // TODO error message
	// TODO strcdup(&line[i], ' ') --> filename
	data->textures.north.ptr = mlx_xpm_file_to_image(data->mlx_ptr, , , ); // XXX do we need to get width and height of textures ?
	if (!data->textures.north.ptr)
		return (1); // TODO error message
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i])
		return (1); // TODO error message
	return (0);
}

int	set_south(t_data *data, char *line)
{
	// TODO set_south()
	return (0);
}

int	set_east(t_data *data, char *line)
{
	// TODO set_east()
	return (0);
}

int	set_west(t_data *data, char *line)
{
	// TODO set_west()
	return (0);
}
