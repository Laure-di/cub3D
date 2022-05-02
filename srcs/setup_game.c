/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:42:10 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/02 11:42:03 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	move_player_position(&data->player, data);
	render_background(&data->img, data->textures.floor_color, data->textures.ceiling_color);
	render_map(data->map, data);
	castAllRays(&data->player, data);
	//render_rays(&data->img, data->rays, data->player);
	render_player(data->player, data);
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
