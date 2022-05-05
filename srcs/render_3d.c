/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:28:51 by majacque          #+#    #+#             */
/*   Updated: 2022/05/05 17:41:18 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

// perp_distance --> pour la correction de l'effet fish eye
void	render_3d(t_data *data)
{
	float	project_wall_height;
	// float	perp_distance;
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		i;
	int		y;

	i = 0;
	while (i < NUM_RAYS)
	{
		// perp_distance = data->rays[i].distance * cosf(data->rays[i].angle - data->player.rotationAngle);
		project_wall_height = (1 / /* perp_distance */ (data->rays[i].distance * 1)) * DIST_PROJ_PLANE;
		wall_strip_height = (int)project_wall_height;

		wall_top_pixel = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;

		wall_bottom_pixel = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
		if (wall_bottom_pixel > WIN_HEIGHT)
			wall_bottom_pixel = WIN_HEIGHT;

		y = wall_top_pixel;
		while (y < wall_bottom_pixel)
		{
			if (data->rays[i].wasHitVertical)
				img_pix_put(&data->img, i, y, GOLD);
			else
				img_pix_put(&data->img, i, y, SHADE_GOLD);
			y++;
		}
		i++;
	}
}
