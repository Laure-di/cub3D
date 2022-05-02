/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:54:03 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/02 11:40:24 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render_rays(t_img *img, t_ray *rays, t_player player)
{
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(img,player.initial_position.x, player.initial_position.y, rays[i].wallHit.x,rays[i].wallHit.y);
		i++;
	}
}
