/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:56:22 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/09 13:15:32 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, (M_PI * 2));
	if (angle < 0.00)
		angle = (M_PI * 2) + angle;
	return (angle);
}

int	hit_wall(t_position new, t_map map)
{
	int	floorx;
	int	floory;

	floorx = floor(new.x);
	floory = floor(new.y);
	if (floorx < 0 || map.widht <= floorx || floory < 0 || map.height <= floory)
		return (1);
	return (map.matrix[floory][floorx] == '1');
}

void	move_player_position(t_player *player, t_data *data)
{
	float		move_step;
	t_position	new;

	move_step = player->walk_direction * player->walk_speed * MOVE_SPEED;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	new.x = player->initial_position.x
		+ cos(player->rotation_angle + player->direction) * move_step;
	new.y = player->initial_position.y
		+ sin(player->rotation_angle + player->direction) * move_step;
	if (!hit_wall(new, data->map))
	{
		player->initial_position.x = new.x;
		player->initial_position.y = new.y;
	}
	player->rotation_angle = normalize_angle(player->rotation_angle);
}
