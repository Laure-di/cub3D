/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:54:03 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/02 17:26:11 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render_rays(t_data *data, t_ray *rays, t_player player)
{
	int i;
	int	x;
	int	y;

	x = player.initial_position.x * TILE_SIZE * MINI_SCALE;
	y = player.initial_position.y * TILE_SIZE * MINI_SCALE;
	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(&data->img, x, y,
					rays[i].wallHit.x * TILE_SIZE * MINI_SCALE,
					rays[i].wallHit.y * TILE_SIZE * MINI_SCALE);
		i++;
	}
}
