/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:42:10 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/11 18:16:32 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIX);
	render_map(data->map, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (0);
}

void	launch_game(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	// TODO ajouter handle_keypress
//	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}
