/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/12 22:18:22 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_rect	create_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.pos.x = x * MINI_SCALE;
	rect.pos.y = y * MINI_SCALE;
	rect.width = width * MINI_SCALE;
	rect.height	= height * MINI_SCALE;
	return (rect);
}

void	render_map(t_map map, t_data *data)
{
	int	x;
	int	y;
	t_minimap	mini;
	t_rect		rect;

	y = 0;
	mini.tile_width = (WIN_WIDTH / map.widht);
	mini.tile_height = (WIN_HEIGHT / map.height);
	while (y < map.height - 1)
	{
		x = 0;
		while (x < map.widht)
		{
			mini.tile.x = x * mini.tile_width;
			mini.tile.y = y * mini.tile_height;
			mini.tile_color = create_rgb(255, 255, 255);
			rect = create_rect(mini.tile.x, mini.tile.y, mini.tile_width, mini.tile_height);
			if (map.matrix[y][x] == '1')
				mini.tile_color = create_rgb(0, 0, 0);
			if (is_player(map.matrix[y][x]))
				mini.tile_color = GOLD;
		//	tile_color = map.matrix[i][y] != 0 ? 255 : 0;
			render_scale_rect(&data->img, rect, mini.tile_color);
			x++;
		}
		y++;
	}
}
