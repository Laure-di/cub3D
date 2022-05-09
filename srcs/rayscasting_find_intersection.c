/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting_find_intersection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:26:57 by lmasson           #+#    #+#             */
/*   Updated: 2022/05/09 14:33:21 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	vertical_intersection(t_data *data, t_ray *ray,
		t_position intercept, t_position step)
{
	t_position	next;
	float		distance;

	while (0 <= intercept.x && intercept.x < WIN_WIDTH
		&& 0 <= intercept.y && intercept.y < WIN_HEIGHT)
	{
		next.x = intercept.x;
		next.y = intercept.y;
		if (ray->is_facing_left)
			next.x -= 1.0;
		if (hit_wall(next, data->map))
		{
			distance
				= distance_between_points(data->player.initial_position,
					intercept);
			if (distance < ray->distance || ray->distance == 0.0)
			{
				ray->distance = distance;
				update_ray(ray, intercept);
				break ;
			}
		}
		intercept.x += step.x;
		intercept.y += step.y;
	}
}

void	cast_vertical_rays(t_data *data, t_ray *ray)
{
	t_position	intercept;
	t_position	step;

	intercept.x = floor(data->player.initial_position.x / 1) * 1;
	if (!ray->is_facing_left)
		intercept.x += 1;
	intercept.y = data->player.initial_position.y
		+ ((intercept.x - data->player.initial_position.x) * tan(ray->angle));
	step.x = 1;
	if (ray->is_facing_left)
		step.x *= -1;
	step.y = 1 * tan(ray->angle);
	if ((!ray->is_facing_down && 0 < step.y)
		|| (ray->is_facing_down && step.y < 0))
		step.y *= -1;
	vertical_intersection(data, ray, intercept, step);
}

void	horizontal_intersection(t_data *data, t_ray *ray
		, t_position intercept, t_position step)
{
	t_position	next;

	while (0 <= intercept.x && intercept.x < WIN_WIDTH
		&& 0 <= intercept.y && intercept.y < WIN_HEIGHT)
	{
		next.x = intercept.x;
		next.y = intercept.y;
		if (!ray->is_facing_down)
			next.y -= 1;
		ray->wall_hit_content = hit_wall(next, data->map);
		if (ray->wall_hit_content == 1)
		{
			ray->wall_hit.x = intercept.x;
			ray->wall_hit.y = intercept.y;
			ray->was_hit_vertical = 0;
			ray->hit_north = !ray->is_facing_up;
			ray->hit_south = !ray->hit_north;
			ray->distance
				= distance_between_points(data->player.initial_position,
					intercept);
			break ;
		}
		intercept.x += step.x;
		intercept.y += step.y;
	}
}

void	cast_horizontal_rays(t_data *data, t_ray *ray)
{
	t_position	intercept;
	t_position	step;

	intercept.y = floor(data->player.initial_position.y / 1) * 1;
	if (ray->is_facing_down)
		intercept.y += 1;
	intercept.x = data->player.initial_position.x
		+ ((intercept.y - data->player.initial_position.y) / tan(ray->angle));
	step.y = 1;
	if (!ray->is_facing_down)
		step.y *= -1;
	step.x = 1 / tan(ray->angle);
	if ((ray->is_facing_left && 0 < step.x)
		|| (!ray->is_facing_left && step.x < 0))
		step.x *= -1;
	horizontal_intersection(data, ray, intercept, step);
}
