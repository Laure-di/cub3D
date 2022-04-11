/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:04 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/11 18:16:36 by lauremass        ###   ########.fr       */
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

int	render_tile(t_img *img, t_minimap mini)
{
	int	i;
	int	j;

	i = mini.tile_y;
	while (i < mini.tile_y + mini.tile_height)
	{
		j = mini.tile_x;
		while (j < mini.tile_x + mini.tile_width)
			img_pix_put(img, j++, i, mini.tile_color);
		i++;
	}
	return (0);
}
