/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:56:22 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/27 15:08:54 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	move_player_position(t_player *player)
{
	float		moveStep;
	t_position	new;

	moveStep = player->walkDirection * player->walkSpeed * DELTA_TIME;
	player->rotationAngle += player->turnDirection * player->turnSpeed * ROTATION_SPEED;
	new.x = player->initial_position.x + cos(player->rotationAngle + player->direction) * moveStep;
	new.y = player->initial_position.y + sin(player->rotationAngle + player->direction) * moveStep;
//	if (!HitWall())
//	{
		player->initial_position.x = new.x;
		player->initial_position.y = new.y;
//	}
	// TODO check if a wall near by
}
