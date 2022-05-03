/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:39:38 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/03 14:23:59 by lmasson          ###   ########.fr       */
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
	if (rayAngle > (0.5 * M_PI) && rayAngle < (1.5 * M_PI))
		ray.isFacingLeft = 1;
	ray.isFacingUp = !ray.isFacingDown;
	ray.isFacingRight = !ray.isFacingLeft;
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
	t_position 	next;
	int		hit;
	float		distance;

	while (0 <= intercept.x && intercept.x < WIN_WIDTH && 0 <= intercept.y && intercept.y < WIN_HEIGHT)
	{
		next.x = intercept.x;
		next.y = intercept.y;
		if (ray->isFacingLeft)
			next.x -= 1.0;
		hit = hitWall(next, data->map);
		//printf("Vertical hit = %i\n", hit);
		if (hit == 1)
		{
			distance = distanceBetweenPoints(data->player.initial_position, intercept); 
			if (distance < ray->distance || ray->distance == 0)
			{
				ray->wallHit.x = intercept.x;
				ray->wallHit.y = intercept.y;
				ray->wasHitVertical = 1;
				ray->wallHitContent = hit;
				ray->distance = distance;
				break ;
			}
		}
		intercept.x += step.x;
		intercept.y += step.y;
	}
}

void	castVerticalRay(t_data *data, t_ray *ray)
{
	t_position intercept;
	t_position	step;

	intercept.x = floor(data->player.initial_position.x);
	if (!ray->isFacingLeft)
		intercept.x += 1;
	intercept.y = data->player.initial_position.y + ((intercept.x - data->player.initial_position.x) * tan(ray->angle));
	step.x = 1;
	if (ray->isFacingLeft)
		step.x *= -1;
	step.y = 1 * tan(ray->angle);
	if ((!ray->isFacingDown && 0 < step.y) || (ray->isFacingDown && step.y < 0))
		step.y *= -1;
	verticalIntersection(data, ray, intercept, step);
}

void	horizontalIntersection(t_data *data, t_ray *ray, t_position intercept, t_position step)
{
	t_position next;

	while (0 <= intercept.x && intercept.x < WIN_WIDTH && 0 <= intercept.y && intercept.y < WIN_HEIGHT)
	{
		next.x = intercept.x;
		next.y = intercept.y;
		if (!ray->isFacingDown)
			next.y -= 1;
		ray->wallHitContent = hitWall(next, data->map);
		//printf("Horizontal hit : %i\n", ray->wallHitContent);
		if (ray->wallHitContent == 1)
		{
			ray->wallHit.x = intercept.x;
			ray->wallHit.y = intercept.y;
			ray->wasHitVertical = 0;
			ray->distance = distanceBetweenPoints(data->player.initial_position, intercept);
			break ;
		}
		intercept.x += step.x;
		intercept.y += step.y;
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
	if (!ray->isFacingDown)
		step.y *= -1;
	step.x = 1 / tan(ray->angle);
	if ((ray->isFacingLeft && 0 < step.x) || (!ray->isFacingLeft && step.x < 0))
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

