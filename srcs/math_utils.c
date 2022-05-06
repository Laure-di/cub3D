/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:15:21 by lmasson           #+#    #+#             */
/*   Updated: 2022/05/05 16:27:41 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

float	distanceBetweenPoints(t_position start, t_position end)
{
	return (sqrt((end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y)));
}

double	deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	rad2deg(double radians)
{
	return (radians * (180 / M_PI));
}

