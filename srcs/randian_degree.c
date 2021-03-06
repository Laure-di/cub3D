/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randian_degree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:15:21 by lmasson           #+#    #+#             */
/*   Updated: 2022/03/10 15:19:52 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

double	deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	rad2deg(double radians)
{
	return (randians * (180 / M_PI));
}

