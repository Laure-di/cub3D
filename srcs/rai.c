/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:08:47 by lmasson           #+#    #+#             */
/*   Updated: 2022/05/03 09:29:24 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_ray	create_ray(float rayAngle)
{
	t_ray	ray;

	 ray.isFacingDown = 0;
	 ray.isFacingRight = 0;
	if (0 < rayAngle && rayAngle < M_PI)
		ray.isFacingDown = 1;
	if (rayAngle < (0.5 * M_PI) || rayAngle > (1.5 * M_PI))
		ray.isFacingRight = 1;
	ray.isFacingUp = !ray.isFacingDown;
	ray.isFacingLeft = !ray.isFacingRight;
	ray.angle = rayAngle;
	ray.wallHit.x = 0;
	ray.wallHit.y = 0;
	ray.distance = 0;
	ray.wasHitVertical = 0;
	ray.wallHitContent = 1;
	return (ray);
}

void	findNextInterceptVrtc(t_data *data, t_ray *ray, t_position intercept, t_position step) //TO_DO reduire la fonction
{
	t_position next;

	next.x = intercept.x;
	next.y = intercept.y;
	while (0 <= next.x && next.x <= WIN_WIDTH && 0 <= next.y && next.y <= WIN_HEIGHT)
	{
		if (ray->isFacingLeft)
			next.x  -= 1;
		ray->wallHitContent = hitWall(next, data->map);
		if (ray->wallHitContent)
		{
				ray->wallHit.x = next.x;
				ray->wallHit.y = next.y;
				ray->wasHitVertical = 1;
				ray->distance = distanceBetweenPoints(data->player.initial_position, ray->wallHit);
				break ;
		}
		else
		{
			next.x += step.x;
			next.y += step.y;
		}
	}
}

void	castVerticalRay(t_data *data, t_ray *ray)
{
	t_position intercept;
	t_position	step;

	intercept.x = floor(data->player.initial_position.x);
	if (ray->isFacingRight)
		intercept.x += 1;
	intercept.y = data->player.initial_position.y + (intercept.x - data->player.initial_position.x) * tan(ray->angle);
	step.x = 1;
	if (ray->isFacingLeft)
		step.x *= -1;
	step.y = 1 * tan(ray->angle);
	if ((ray->isFacingUp && 0 < step.y) || (ray->isFacingRight && step.y < 0))
		step.x *= -1;
	findNextInterceptVrtc(data, ray, intercept, step);

}

void	findNextInterceptHrzt(t_data *data, t_ray *ray, t_position intercept, t_position step)
{
	t_position next;

	next.x = intercept.x;
	next.y = intercept.y;
	while (0 <= next.x && next.x <= WIN_WIDTH && 0 <= next.y && next.y <= WIN_HEIGHT)
	{
		if (!ray->isFacingDown)
			next.y -= 1;
		ray->wallHitContent = hitWall(next, data->map);
		if (ray->wallHitContent)
		{
			ray->wallHit.x = next.x;
			ray->wallHit.y = next.y;
			ray->wasHitVertical = 0;
			ray->distance = distanceBetweenPoints(data->player.initial_position, ray->wallHit);
			break ;
		}
		else
		{
			next.x += step.x;
			next.y += step.y;
		}
	}
}

void	castHorizontalRay(t_data *data, t_ray *ray)
{
	t_position intercept;
	t_position	step;

	intercept.y = floor(data->player.initial_position.y);
	if (ray->isFacingDown)
		intercept.y += 1;
	intercept.x = data->player.initial_position.x + (intercept.y - data->player.initial_position.y) / tan(ray->angle);
	step.y = 1;
	if (ray->isFacingUp)
		step.y *= -1;
	step.x = 1 / tan(ray->angle);
	if ((ray->isFacingLeft && 0 < step.x) || (ray->isFacingRight && step.x < 0))
		step.x *= -1;
	findNextInterceptHrzt(data, ray, intercept, step);

}


t_ray	find_intersection(t_data *data, float rayAngle)
{
	t_ray	horizontal;
	t_ray	vertical;
	
	rayAngle = normalizeAngle(rayAngle);
	horizontal = create_ray(rayAngle);
	vertical = create_ray(rayAngle);
	castHorizontalRay(data, &horizontal);
	castVerticalRay(data, &vertical);
	if (vertical.distance < horizontal.distance || horizontal.distance == 0)
		return (vertical);
	return (horizontal);
}

void	castAllRays(t_player *player, t_data *data)
{
	float		rayAngle;
	int		stripId;

	stripId = 0;
	rayAngle = player->rotationAngle - (FOV_ANGLE / 2);
	while (stripId < NUM_RAYS)
	{
		data->rays[stripId] = find_intersection(data, rayAngle);
		//castHorizontalRay(data, &data->rays[stripId]);
		//castVerticalRay(data, &data->rays[stripId]);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		stripId++;
	}

}

