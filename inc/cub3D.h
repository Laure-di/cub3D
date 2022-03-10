/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:37:54 by lauremass         #+#    #+#             */
/*   Updated: 2022/03/10 14:09:26 by majacque         ###   ########.fr       */
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

typedef struct s_img
{
	void		*ptr;
	char		*adrr;
	int			bpp;
	int			line_len;
	int			endian;

}				t_img;

typedef struct s_color	t_color;

struct s_color
{
	int	red;
	int	green;
	int	blue;
};

typedef struct s_texture	t_texture;

struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_color	ceiling;
	t_color	ground;
};

typedef struct	s_data
{
	// int			win_size;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_texture	textures;
}				t_data;

#endif
