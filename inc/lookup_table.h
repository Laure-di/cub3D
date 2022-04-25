/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_table.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:12:58 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/25 21:04:50 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_TABLE_H
# define LOOKUP_TABLE_H

# include "cub3D.h"

# define UP XK_w
# define DOWN XK_s
# define LEFT XK_a
# define RIGHT XK_d
# define RO_RIGHT XK_Left
# define RO_LEFT XK_Right

typedef struct s_movement
{
	int	keysym;
	int	(*f)(t_data *, t_player *);
}	t_movement;

int	move_front(t_data *data);
int	move_back(t_data *data);
int	move_left(t_data *data);
int	move_right(t_data *data);
int	rotation_right(t_data *data);
int	rotation_left(t_data *data);

static const t_movement g_movement[] = {
	{FRONT, move_front},
	{BACK, move_back},
	{LEFT, move_left},
	{RIGHT, move_right},
	{RO_RIGHT, rotation_right},
	{RO_LEFT, rotation_left},
	{0, NULL}
};

#endif