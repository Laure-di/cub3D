/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:52:42 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/27 15:32:26 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int			handle_keypress(int keysim, t_data *data)
{
	t_player *player;

	player = &data->player;
	if (keysim == ESCAPE)
		mlx_loop_end(data->mlx_ptr);
	if (keysim == UP || keysim == RIGHT)
		player->walkDirection = 1;
	if (keysim == DOWN || keysim == LEFT)
		player->walkDirection = -1;
	if (keysim == LEFT || keysim == RIGHT)
		player->direction = M_PI / 2;
	if (keysim == RO_RIGHT)
		player->turnDirection = 1;
	if (keysim == RO_LEFT)
		player->turnDirection = -1;
	return (1);
}

int		handle_release(int keysim, t_data *data)
{
	t_player *player;

	player = &data->player;
	if (keysim == UP || keysim == DOWN || keysim == RIGHT || keysim == LEFT)
		player->walkDirection = 0;
	if (keysim == LEFT || keysim == RIGHT)
		player->direction = 0;
	if (keysim == RO_RIGHT || keysim == RO_LEFT)
		player->turnDirection = 0;
	if (keysim == DOWN)
		player->turnDirection = 0;
	return (1);
}

void		mng_event_input(t_data *data)
{
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, mlx_loop_end, data->mlx_ptr);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyRelease, &handle_release, data);
}
