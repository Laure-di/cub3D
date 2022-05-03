/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:56:22 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/03 16:37:04 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

float	normalizeAngle(float angle)
{
	angle = remainder(angle, (M_PI * 2));
	if (angle < 0)
		angle = M_PI * 2 + angle;
	return (angle);
}

int		hitWall(t_position new, t_map map)
{
	int floorx;
	int	floory;

	floorx = floor(new.x);
	floory = floor(new.y);
	if (floorx < 0 || map.widht <= floorx || floory < 0 || map.height <= floory)
		return (1);
	return (map.matrix[floory][floorx] == '1');
}

void	move_player_position(t_player *player, t_data *data)
{
	float		moveStep;
	t_position	new;

	moveStep = player->walkDirection * player->walkSpeed * DELTA_TIME;
	player->rotationAngle += player->turnDirection * player->turnSpeed * ROTATION_SPEED;
	player->rotationAngle = normalizeAngle(player->rotationAngle);
	new.x = player->initial_position.x + cos(player->rotationAngle + player->direction) * moveStep;
	new.y = player->initial_position.y + sin(player->rotationAngle + player->direction) * moveStep;
	if (!hitWall(new, data->map))
	{
		player->initial_position.x = new.x;
		player->initial_position.y = new.y;
	}
}
