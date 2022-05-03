/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:39:38 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/03 11:54:21 by lmasson          ###   ########.fr       */
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

void	verticalIntersection(t_data *data, t_ray *ray, t_position intercept, t_position step) //TO_DO reduire la fonction
{
	t_position next;
	int	hit;
	float	distance;

	next.x = intercept.x;
	next.y = intercept.y;
	while (0 <= next.x && next.x <= WIN_WIDTH && 0 <= next.y && next.y <= WIN_HEIGHT)
	{
		if (ray->isFacingLeft)
			next.x  -= 1;
		hit = hitWall(next, data->map);
		if (hit == 1)
		{
			distance = distanceBetweenPoints(data->player.initial_position, intercept); 
			if (distance < ray->distance || ray->distance == 0.0)
			{
				ray->wallHit.x = intercept.x;
				ray->wallHit.y = intercept.y;
				ray->wasHitVertical = 1;
				ray->wallHitContent = hit;
				ray->distance = distance;
			}
			break ;
		}
		next.x += step.x;
		next.y += step.y;
	}
}

void	castVerticalRay(t_data *data, t_ray *ray)
{
	t_position intercept;
	t_position	step;

	intercept.x = floor(data->player.initial_position.x);
	if (ray->isFacingRight)
		intercept.x += 1;
	intercept.y = data->player.initial_position.y + ((intercept.x - data->player.initial_position.x) * tan(ray->angle));
	step.x = 1;
	if (ray->isFacingLeft)
		step.x *= -1;
	step.y = 1 * tan(ray->angle);
	if ((ray->isFacingUp && 0 < step.x) || (ray->isFacingRight && step.x < 0))
		step.x *= -1;
	verticalIntersection(data, ray, intercept, step);

}

void	horizontalIntersection(t_data *data, t_ray *ray, t_position intercept, t_position step)
{
	t_position next;

	next.x = intercept.x;
	next.y = intercept.y;
	while (0 <= next.x && next.x < WIN_WIDTH && 0 <= next.y && next.y < WIN_HEIGHT)
	{
		if (ray->isFacingUp)
			next.y -= 1;
		ray->wallHitContent = hitWall(next, data->map);
		if (ray->wallHitContent == 1)
		{
			ray->wallHit.x = intercept.x;
			ray->wallHit.y = intercept.y;
			ray->wasHitVertical = 0;
			ray->distance = distanceBetweenPoints(data->player.initial_position, ray->wallHit);
			break ;
		}
		next.x += step.x;
		next.y += step.y;
	}
}

void	castHorizontalRay(t_data *data, t_ray *ray)
{
	t_position intercept;
	t_position	step;

	intercept.y = floor(data->player.initial_position.y);
	if (ray->isFacingDown)
		intercept.y += 1;
	intercept.x = data->player.initial_position.x + ((intercept.y - data->player.initial_position.y) / tan(ray->angle));
	step.y = 1;
	if (ray->isFacingUp)
		step.y *= -1;
	step.x = 1 / tan(ray->angle);
	if ((ray->isFacingLeft && 0 < step.x) || (ray->isFacingRight && step.x < 0))
		step.x *= -1;
	horizontalIntersection(data, ray, intercept, step);

}

void	castAllRays(t_player *player, t_data *data)
{
	float	rayAngle;
	int		stripId;

	rayAngle = player->rotationAngle - (FOV_ANGLE / 2);
	stripId = 0;
	while (stripId < NUM_RAYS)
	{
		data->rays[stripId] = create_ray(rayAngle);
		castHorizontalRay(data, &data->rays[stripId]);
		castVerticalRay(data, &data->rays[stripId]);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		stripId++;
	}

}

