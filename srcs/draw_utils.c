/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:04 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/08 17:08:03 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	render_tile(t_img *img, int tile_y, int tile_x, int tile_color, int width, int height)
{
	int	i;
	int	j;

	i = tile_y;
	while (i < tile_y + height)
	{
		j = tile_x;
		while (j < tile_x + width)
			img_pix_put(img, j++, i, tile_color);
		i++;
	}
	return (0);
}
