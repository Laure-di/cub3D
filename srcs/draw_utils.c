/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:04 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/03 15:12:40 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	render_tile(t_img *img, int tile_y, int tile_x, int tile_color)
{
	int	i;
	int	j;

	i = tile_y;
	while (i < tile_y + TILE_SIZE)
	{
		j = tile_x;
		while (j < tile_x + TILE_SIZE)
			img_pix_put(img, j++, i, tile_color);
		i++;
	}
	return (0);
}
