/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:04 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/11 14:05:53 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

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
