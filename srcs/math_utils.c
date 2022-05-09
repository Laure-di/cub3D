/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:15:21 by lmasson           #+#    #+#             */
/*   Updated: 2022/05/09 12:59:07 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

float	distance_between_points(t_position start, t_position end)
{
	return (sqrt((end.x - start.x) * (end.x - start.x)
			+ (end.y - start.y) * (end.y - start.y)));
}
