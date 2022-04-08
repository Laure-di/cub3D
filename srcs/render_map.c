/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/08 17:07:58 by lauremass        ###   ########.fr       */
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
	while (i < map.height)
	{
		y = 0;
		while (y < map.widht)
		{
			tile_x = y * (WIN_WIDTH / map.widht);
			tile_y = i * (WIN_HEIGHT / map.height);
			tile_color = map.matrix[i][y] != 0 ? 255 : 0;
			render_tile(&data->img, tile_y, tile_x, create_rgb(tile_color, tile_color, tile_color), (WIN_WIDTH / map.widht), (WIN_HEIGHT / map.height));
			y++;
		}
		i++;
	}
}
