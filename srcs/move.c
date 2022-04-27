/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:56:22 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/27 16:33:04 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int		hitWall(t_position new, t_map map)
{
	int floorx;
	int	floory;

	floorx = floor(new.x);
	floory = floor(new.y);
	if (floorx < 0 || map.widht <= floorx || floory < 0 || map.height <= floory)
		return (1);
	return (map.matrix[floory][floorx] != '0');
}

void	move_player_position(t_player *player, t_data *data)
{
	float		moveStep;
	t_position	new;

	moveStep = player->walkDirection * player->walkSpeed * DELTA_TIME;
	player->rotationAngle += player->turnDirection * player->turnSpeed * ROTATION_SPEED;
	new.x = player->initial_position.x + cos(player->rotationAngle + player->direction) * moveStep;
	new.y = player->initial_position.y + sin(player->rotationAngle + player->direction) * moveStep;
	if (!hitWall(new, data->map))
	{
		player->initial_position.x = new.x;
		player->initial_position.y = new.y;
	}
}
