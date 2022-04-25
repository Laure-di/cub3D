/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:04 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/22 17:59:15 by lauremass        ###   ########.fr       */
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

int	render_scale_rect(t_img *img, t_rect rect, int color)
{
	int	i;
	int	j;

	i = rect.pos.y;
	while (i < rect.pos.y + rect.height)
	{
		j = rect.pos.x;
		while (j < rect.pos.x + rect.width)
			img_pix_put(img, j++, i, color);
		i++;
	}
	return (0);
}

