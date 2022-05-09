/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:39:38 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/09 14:28:33 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_ray	create_ray(float ray_angle)
{
	t_ray	ray;

	ray.is_facing_down = 0;
	ray.is_facing_left = 0;
	ray.angle = normalize_angle(ray_angle);
	if (0 < ray.angle && ray.angle < M_PI)
		ray.is_facing_down = 1;
	if (ray.angle > (0.5 * M_PI) && ray.angle < (1.5 * M_PI))
		ray.is_facing_left = 1;
	ray.is_facing_up = !ray.is_facing_down;
	ray.is_facing_right = !ray.is_facing_left;
	ray.wall_hit.x = 0;
	ray.wall_hit.y = 0;
	ray.distance = 0;
	ray.hit_north = 0;
	ray.hit_south = 0;
	ray.hit_east = 0;
	ray.hit_west = 0;
	ray.was_hit_vertical = 0;
	ray.wall_hit_content = 1;
	return (ray);
}

void	update_ray(t_ray *ray, t_position intercept)
{
	ray->wall_hit.x = intercept.x;
	ray->wall_hit.y = intercept.y;
	ray->was_hit_vertical = 1;
	ray->wall_hit_content = 1;
	ray->hit_west = !ray->is_facing_left;
	ray->hit_east = !ray->hit_west;
	ray->hit_north = 0;
	ray->hit_south = 0;
}

void	cast_all_rays(t_player *player, t_data *data)
{
	float	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = player->rotation_angle - (FOV_ANGLE / 2);
	while (strip_id < NUM_RAYS)
	{
		ray_angle += FOV_ANGLE / NUM_RAYS;
		data->rays[strip_id] = create_ray(ray_angle);
		cast_horizontal_rays(data, &data->rays[strip_id]);
		cast_vertical_rays(data, &data->rays[strip_id]);
		strip_id++;
	}
}
