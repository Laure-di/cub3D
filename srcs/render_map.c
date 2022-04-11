/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/11 14:05:51 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render_map(t_map map, t_data *data)
{
	int	i;
	int	y;
	int	tile_x;
	int	tile_y;
	int	tile_color;

	i = 0;
	while (i < map.height - 1)
	{
		y = 0;
		while (y < map.widht)
		{
			tile_x = y * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			tile_color = 255;
			if (map.matrix[i][y] == '1')
				tile_color = 0;
		//	tile_color = map.matrix[i][y] != 0 ? 255 : 0;
			render_tile(&data->img, tile_y, tile_x, create_rgb(tile_color, tile_color, tile_color));
			y++;
		}
		i++;
	}
}
