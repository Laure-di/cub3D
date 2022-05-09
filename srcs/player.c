/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:27:27 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/09 13:32:18 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_position	find_position(char **matrix,
	char player_orientation, t_map map)
{
	t_position	position;
	int			y;
	int			x;

	y = 0;
	position.y = 0;
	position.x = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.widht)
		{
			if (matrix[y][x] == player_orientation)
			{
				position.y = y;
				position.x = x;
				return (position);
			}
			x++;
		}
		y++;
	}
	return (position);
}

static char	__find_orientation(char **matrix, t_map map)
{
	int		y;
	int		i;
	char	orientation;

	y = 0;
	while (y < map.height)
	{
		i = 0;
		while (i < map.widht)
		{
			orientation = matrix[y][i];
			if (orientation != '0' && orientation != '1' && orientation != 32)
				return (orientation);
			i++;
		}
		y++;
	}
	return (orientation);
}

t_player	initialize_player(t_map map)
{
	t_player	player;
	char		player_orientation;

	player_orientation = __find_orientation(map.matrix, map);
	player.initial_position = find_position(map.matrix,
			player_orientation, map);
	player.width = 1;
	player.height = 1;
	player.turn_direction = 0;
	player.walk_direction = 0;
	if (player_orientation == 'S')
		player.rotation_angle = M_PI / 2;
	else if (player_orientation == 'N')
		player.rotation_angle = (M_PI * 3) / 2;
	else if (player_orientation == 'W')
		player.rotation_angle = M_PI;
	else
		player.rotation_angle = 0;
	player.walk_speed = MOVE_SPEED;
	player.turn_speed = (ROTATION_SPEED * M_PI) / 180;
	player.direction = 0;
	player.move = 0;
	return (player);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
