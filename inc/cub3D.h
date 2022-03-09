/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:37:54 by lauremass         #+#    #+#             */
/*   Updated: 2022/03/09 16:29:05 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void		*mlx_img;
	char		*adrr;
	int			bpp;
	int			line_len;
	int			endian;

}				t_img;

typedef struct	s_data
{
	int			win_size;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img		img;
}				t_data;

#endif
