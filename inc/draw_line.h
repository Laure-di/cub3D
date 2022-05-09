/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:51:34 by majacque          #+#    #+#             */
/*   Updated: 2022/05/09 15:20:23 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

typedef struct s_draw	t_draw;

struct s_draw
{
	t_offset	dist;
	t_offset	s;
	int			error;
};

void	draw_line(t_img *img, t_offset a, t_offset b);

#endif
