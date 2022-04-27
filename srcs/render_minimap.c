/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/27 01:33:03 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_rect	create_scale_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.pos.x = x * MINI_SCALE;
	rect.pos.y = y * MINI_SCALE;
	rect.width = width * MINI_SCALE;
	rect.height	= height * MINI_SCALE;
	return (rect);
}

void	render_miniplayer(t_player player, t_data *data)
{
	int	x;
	int	y;
	t_rect	rect;

	x = player.initial_position.x * (WIN_WIDTH / data->map.widht) + ((WIN_WIDTH / data->map.widht) / 2);
	y = player.initial_position.y * (WIN_HEIGHT / data->map.height) + ((WIN_HEIGHT / data->map.height) / 2);
	rect = create_scale_rect(x, y, player.width, player.height);
	render_rect(&data->img, rect, RED);
}

void	render_minimap(t_map map, t_data *data)
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
			rect = create_scale_rect(mini.tile.x, mini.tile.y, mini.tile_width, mini.tile_height);
			if (map.matrix[y][x] == '1')
				mini.tile_color = create_rgb(0, 0, 0);
			render_rect(&data->img, rect, mini.tile_color);
			x++;
		}
		y++;
	}
}
