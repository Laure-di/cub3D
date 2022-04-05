/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:37:54 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/05 18:13:57 by majacque         ###   ########.fr       */
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
# include "../libft/libft.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1024
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 512
# endif
// TODO integrer tile_size dans 

# define TILE_SIZE 64
# define FOV_ANGLE (60 * M_PI / 180)
# define NUM_RAYS WINDOW_WIDTH

typedef struct	s_img	t_img;

typedef struct s_img
{
	void		*ptr;
	int			width;
	int			height;
	char		*adrr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;


typedef struct s_texture	t_texture;

typedef struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_map	t_map;

typedef struct s_map
{
	char	**matrix;
	int		widht;
	int		height;
	int		player_pos_x;
	int		player_pos_y;
}	t_map;

typedef struct s_data	t_data;

typedef struct	s_data
{
	// int			win_size;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_texture	textures;
	t_map		map;
} t_data;

typedef struct s_position	t_position;

typedef struct s_position
{
	float	x;
	float	y;
}	t_position;

typedef struct s_player	t_player;

typedef	struct s_player
{
	t_position	initial_position;
	float		width;
	float		height;
	int			turnDirection;
	int			walkDirection;
	float		rotationAngle;
	float		walkSpeed;
	float		turnSpeed;
}	t_player;


int		main(int argc, char **argv);
void	launch_game(t_data *data);
int		render(t_data *data);
void	render_map(t_map map, t_data *data);
int		render_tile(t_img *img, int tile_y, int tile_x, int tile_color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		parsing(t_data *data, char const *const filename);
int		check_map(t_map *map);
void	clear_map(char ***map, int height);

#endif
