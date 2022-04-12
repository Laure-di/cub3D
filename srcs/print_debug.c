/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:20:26 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/12 09:50:44 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	print_data(t_data data)
{
	int	i;

	i = 0;
	while (i < data.map.height)
		printf("%s\n", data.map.matrix[i++]);
	printf("width : %i, height : %i\n", data.map.widht, data.map.height);
	printf("player position : %f, height : %f\n", data.player.initial_position.x, data.player.initial_position.y);
}
