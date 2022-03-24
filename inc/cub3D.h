/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:37:54 by lauremass         #+#    #+#             */
/*   Updated: 2022/03/22 21:30:28 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1024
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 512
# endif

typedef struct s_img	t_img;

typedef s_img
{
	void		*ptr;
	int			width;
	int			height;
	char		*adrr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;


typedef struct s_texture	t_texture;

typedef s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	int		floor_color;
	int		ceiling_color;
};

typedef struct s_map	t_map;

struct s_map
{
	char	**matrix;
	int		widht;
	int		height;
};

typedef struct s_data	t_data;

typedef	s_data
{
	// int			win_size;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_texture	textures;
	t_map		map;
}				t_data;

typedef struct s_position	t_position;

typedef s_position
{
	float	x;
	float	y;
}	t_position;

typedef struct s_player	t_player;

typedef	s_player
{
	t_position	initial_position;
	float		width;
	float		height;
	int			turnDirection;
	int			walkDiretion;
	float		rotationAngle;
	float		walkSpeed;
	float		turnSpeed;
}

#endif
