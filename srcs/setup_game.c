/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:42:10 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/27 15:32:58 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	move_player_position(&data->player, data);
	render_background(&data->img, GOLD);
	/*********** BONUS PART **************/
	render_minimap(data->map, data);
	render_miniplayer(data->player, data);
	/*********** END *********************/
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (1);
}

void	launch_game(t_data *data)
{
	mng_event_input(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_loop(data->mlx_ptr);
}
