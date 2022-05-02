/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:04 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/30 17:05:01 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	abs_val(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	draw_line(t_img *img, int x0, int y0, int x1, int y1)
{
	int	dx = abs_val(x1 - x0);
	int	sx = x0 < x1 ? 1 : -1;
	int	dy = -abs_val(y1 - y0);
	int	sy = y0 < y1 ? 1 : -1;
	int	error = dx + dy;

	while (1)
	{
		img_pix_put(img, x0, y0, RED);
		if (x0 == x1 && y0 == y1)
			break;
		int	e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break;
			error = error + dy;
			x0 = x0 + sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break;
			error = error + dx;
			y0 = y0 + sy;
		}
	}
}

void	render_background(t_img *img, int floorColor, int ceilColor)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(img, j++, i, ceilColor);
		++i;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(img, j++, i, floorColor);
		i++;
	}
}

int	render_rect(t_img *img, t_rect rect, int color)
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

