/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:28:51 by majacque          #+#    #+#             */
/*   Updated: 2022/05/03 11:50:30 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render_3d(t_data *data)
{
	float	distance_proj_plane;
	float	project_wall_height;
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		i;
	int		y;

	distance_proj_plane = (WIN_WIDTH / 2) / tanf(FOV_ANGLE / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		project_wall_height = (TILE_SIZE / data->rays[i].distance) * distance_proj_plane;
		wall_strip_height = (int)project_wall_height;

		wall_top_pixel = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;

		wall_bottom_pixel = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
		if (wall_bottom_pixel > WIN_HEIGHT)
			wall_bottom_pixel = WIN_HEIGHT;
		
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (y < wall_top_pixel)
				img_pix_put(&data->img, i, y, data->textures.ceiling_color);
			else if (y > wall_bottom_pixel)
				img_pix_put(&data->img, i, y, data->textures.floor_color);
			else
				img_pix_put(&data->img, i, y, GOLD);
			y++;
		}
		i++;
	}
}
