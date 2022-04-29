/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:37:17 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/29 11:32:40 by majacque         ###   ########.fr       */
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

int	abs_val(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	draw_line(t_img *img, int x0, int y0, int x1, int y1)
{
	int	dx = abs_val(x1 - x0);
	int	sx = x0 < x1 ? 1 : -1;
	int	dy = -abs_val(y1 - y0);
	int	sy = y0 < y1 ? 1 : -1;
	int	error = dx + dy;

	while (1)
	{
		img_pix_put(img, x0, y0, RED);
		if (x0 == x1 && y0 == y1)
			break;
		int	e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break;
			error = error + dy;
			x0 = x0 + sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break;
			error = error + dx;
			y0 = y0 + sy;
		}
	}
}

void	draw_all_rays(t_player *player, t_img *img, int x, int y)
{
	float	rayAngle;
	int		rayId;

	rayAngle = player->rotationAngle - (FOV_ANGLE / 2);
	rayId = 0;

	while (rayId < NUM_RAYS)
	{
		draw_line(img, x, y, 
					x - (cos(rayAngle) * 20),
					y - (sin(rayAngle) * 20));
		rayAngle += FOV_ANGLE / NUM_RAYS;
		rayId++;
	}
}

void	render_miniplayer(t_player player, t_data *data)
{
	int	x;
	int	y;
	t_rect	rect;

	x = player.initial_position.x * (WIN_WIDTH / data->map.widht);
	y = player.initial_position.y * (WIN_HEIGHT / data->map.height);
	rect = create_scale_rect(x, y, player.width, player.height);
	render_rect(&data->img, rect, RED);
	// TODO render FOV
	draw_all_rays(&player, &data->img, x, y);
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
