/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:37:54 by lauremass         #+#    #+#             */
/*   Updated: 2022/05/02 13:25:17 by lmasson          ###   ########.fr       */

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
# include "lookup_table.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1024
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 512
# endif

# define FOV_ANGLE (60 * M_PI / 180)
# define NUM_RAYS WIN_WIDTH
# define MINI_SCALE 0.3
# define DELTA_TIME 0.003
# define ROTATION_SPEED	0.3

# define BLACK_PIX 0x000000
# define WHITE 0xffffff
# define GOLD 0xffd700
# define RED 0xff0000

typedef struct	s_img	t_img;
typedef struct s_texture	t_texture;
typedef struct s_map	t_map;
typedef struct s_minimap t_minimap;
typedef struct s_data	t_data;
typedef struct s_position	t_position;
typedef struct s_player	t_player;
typedef struct s_rect	t_rect;

typedef struct s_position
{
	float	x;
	float	y;
}	t_position;

typedef struct	s_rect
{
	t_position	pos;
	int			width;
	int			height;
	int			color;
}	t_rect;

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

typedef struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_map
{
	char	**matrix;
	int		widht;
	int		height;
	int		player_pos_x;
	int		player_pos_y;
}	t_map;

typedef struct	s_minimap
{
	t_position	tile;
	int	tile_width;
	int	tile_height;
	int	tile_color;
}	t_minimap;

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
	float		direction;
}	t_player;

typedef struct s_ray
{
	float	angle;
	t_position	wallHit;
	float	distance;
	int		wasHitVertical;
	int		isFacingUp;
	int		isFacingDown;
	int		isFacingLeft;
	int		isFacingRight;
	int		wallHitContent;
} t_ray;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_texture	textures;
	t_map		map;
	t_player	player;
	t_ray		*rays;
} t_data;



int				main(int argc, char **argv);
void			clear_data(t_data *data);
void			launch_game(t_data *data);
int				render(t_data *data);
void			render_minimap(t_map map, t_data *data);
int				render_tile(t_img *img, t_minimap mini);
void			render_background(t_img *img, int floorcolor, int ceilingColor);
void			draw_line(t_img *img, int x0, int y0, int x1, int y1);
int				abs_val(int n);
float			distanceBetweenPoints(t_position start, t_position end);
void			img_pix_put(t_img *img, int x, int y, int color);
int				parsing(t_data *data, char const *const filename);
int				check_map(t_map *map);
void			clear_map(char ***map, int height);
int				create_rgb(int r, int g, int b);
t_player		initialize_player(t_map map);
int				render_rect(t_img *img, t_rect rect, int color);
void			render_miniplayer(t_player player, t_data *data);
t_rect			create_scale_rect(int x, int y, int width, int height);
void			render_map(t_map map, t_data *data);
void			render_player(t_player player, t_data *data);
int				is_player(char c);
void			mng_event_input(t_data *data);
int				handle_keypress(int keysim, t_data *data);
void			move_player_position(t_player *player, t_data *data);
void			render_rays(t_data *data, t_ray *rays, t_player player);
void			castAllRays(t_player *player, t_data *data);
float			normalizeAngle(float angle);
void			move_player_position(t_player *player, t_data *data);
int				hitWall(t_position new, t_map map);
t_ray			find_intersection(t_data *data, float rayAngle);
/****** TO DELETE ********/
void	print_data(t_data data);

#endif
