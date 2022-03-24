/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:27:27 by lauremass         #+#    #+#             */
/*   Updated: 2022/03/22 18:38:08 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_position	__find_position(char **matrix, char player_orientation)
{
	t_position	position;
	int			y;
	int			x;
	
	y = 0;
	ft_bzero(position, sizeof(position));
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
	int		x;
	char	orientation;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][i])
		{
			orientation = matrix[y][i];
			if (orientation != 0 && orientation != 1 && orientation != 32)
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

	ft_bzero(player, sizeof(player));
	player_orientation = find_orientation(map.matrix);
	player.initial_position = find_position(map);
	player.width = 5;
	player.heigth = 5;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = M_PI_2;
	player.walkSpeed = 100;
	player.turnSpeed = 45 * (PI / 180);
	return (player);
}
