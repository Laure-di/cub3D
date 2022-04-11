/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/11 17:55:17 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render_map(t_map map, t_data *data)
{
	int	x;
	int	y;
	t_minimap	mini;

	y = 0;
	mini.tile_width = WIN_WIDTH / map.widht;
	mini.tile_height = WIN_HEIGHT / map.height;
	while (y < map.height - 1)
	{
		x = 0;
		while (x < map.widht)
		{
			mini.tile_x = x * mini.tile_width;
			mini.tile_y = y * mini.tile_height;
			mini.tile_color = create_rgb(255, 255, 255);
			if (map.matrix[y][x] == '1')
				mini.tile_color = create_rgb(0, 0, 0);
		//	tile_color = map.matrix[i][y] != 0 ? 255 : 0;
			render_tile(&data->img, mini);
			x++;
		}
		y++;
	}
}
