/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/02 17:23:32 by lmasson          ###   ########.fr       */
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

	x = player.initial_position.x * TILE_SIZE;
	y = player.initial_position.y * TILE_SIZE;
	rect = create_scale_rect(x, y, player.width, player.height);
	render_rect(&data->img, rect, RED);
	/* draw_line(&data->img, x, y,
				x - (cos(player.rotationAngle) * 20),
				y - (sin(player.rotationAngle) * 20)); */
}

void	render_minimap(t_map map, t_data *data)
{
	int	x;
	int	y;
	t_minimap	mini;
	t_rect		rect;

	y = 0;
	while (y < map.height - 1)
	{
		x = 0;
		while (x < map.widht)
		{
			mini.tile.x = x * TILE_SIZE;
			mini.tile.y = y * TILE_SIZE;
			mini.tile_color = create_rgb(255, 255, 255);
			rect = create_scale_rect(mini.tile.x, mini.tile.y, TILE_SIZE, TILE_SIZE);
			if (map.matrix[y][x] == '1')
				mini.tile_color = create_rgb(0, 0, 0);
			render_rect(&data->img, rect, mini.tile_color);
			x++;
		}
		y++;
	}
}
