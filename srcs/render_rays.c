/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:54:03 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/09 15:51:52 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/draw_line.h"

void	render_rays(t_data *data, t_ray *rays, t_player player)
{
	int			i;
	t_offset	a;
	t_offset	b;

	a.x = player.initial_position.x * MINI_SCALE * TILE_SIZE;
	a.y = player.initial_position.y * MINI_SCALE * TILE_SIZE;
	i = 0;
	while (i < NUM_RAYS)
	{
		b.x = rays[i].wall_hit.x * MINI_SCALE * TILE_SIZE;
		b.y = rays[i].wall_hit.y * MINI_SCALE * TILE_SIZE;
		draw_line(&data->img, a, b);
		i++;
	}
}
