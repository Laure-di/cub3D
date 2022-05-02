/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:54:03 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/02 15:26:50 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render_rays(t_data *data, t_ray *rays, t_player player)
{
	int i;
	int	x;
	int	y;

	x = player.initial_position.x * (WIN_WIDTH / data->map.widht);
	y = player.initial_position.y * (WIN_HEIGHT / data->map.height);
	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(&data->img, x, y,
					rays[i].wallHit.x * (WIN_WIDTH / data->map.widht),
					rays[i].wallHit.y * (WIN_HEIGHT / data->map.height));
		i++;
	}
}
