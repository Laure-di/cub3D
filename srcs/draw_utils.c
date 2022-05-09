/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:04 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/09 15:49:19 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/draw_line.h"

int	abs_val(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	__init_draw(t_draw *draw, t_offset a, t_offset b)
{
	draw->dist.x = abs_val(b.x - a.x);
	draw->dist.y = -abs_val(b.y - a.y);
	draw->s.x = -(a.x > b.x) | 1;
	draw->s.y = -(a.y > b.y) | 1;
	draw->error = draw->dist.x + draw->dist.y;
}

void	draw_line(t_img *img, t_offset a, t_offset b)
{
	t_draw	draw;
	int		e2;

	__init_draw(&draw, a, b);
	while (1)
	{
		img_pix_put(img, a.x, a.y, RED);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = 2 * draw.error;
		if (e2 >= draw.dist.y)
		{
			if (a.x == b.x)
				break ;
			draw.error += draw.dist.y;
			a.x += draw.s.x;
		}
		if (e2 <= draw.dist.x)
		{
			if (a.y == b.y)
				break ;
			draw.error += draw.dist.x;
			a.y += draw.s.y;
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
