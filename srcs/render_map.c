/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/30 12:53:18 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_rect	create_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.pos.x = x;
	rect.pos.y = y;
	rect.width = width;
	rect.height	= height;
	return (rect);
}

void	render_player(t_player player, t_data *data)
{
	int	x;
	int	y;
	t_rect	rect;

	x = player.initial_position.x * (WIN_WIDTH / data->map.widht);
	y = player.initial_position.y * (WIN_HEIGHT / data->map.height);
	rect = create_rect(x, y, player.width, player.height);
	render_rect(&data->img, rect, RED);
	// TODO render FOV
	draw_line(&data->img, x, y,
				x - (cos(player.rotationAngle) * 20),
				y - (sin(player.rotationAngle) * 20));
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
			render_rect(&data->img, rect, mini.tile_color);
			x++;
		}
		y++;
	}
}
