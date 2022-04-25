/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:27:27 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/25 13:45:29 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_position	__find_position(char **matrix, char player_orientation)
{
	t_position	position;
	int			y;
	int			x;

	y = 0;
	position.y = 0;
	position.x = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
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

static char			__find_orientation(char **matrix)
{
	int		y;
	int		i;
	char	orientation;

	y = 0;
	while (matrix[y])
	{
		i = 0;
		while (matrix[y][i])
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

t_player		initialize_player(t_map map)
{
	t_player	player;
	char		player_orientation;

	player_orientation = __find_orientation(map.matrix);
	player.initial_position = __find_position(map.matrix, player_orientation);
	player.width = 30;
	player.height = 30;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = M_PI_2;
	player.walkSpeed = 100;
	player.turnSpeed = 45 * (M_PI / 180);
	return (player);
}

int		is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
