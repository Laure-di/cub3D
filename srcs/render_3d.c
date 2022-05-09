/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:28:51 by majacque          #+#    #+#             */
/*   Updated: 2022/05/09 15:32:01 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	find_x_offset(t_ray ray, t_img texture)
{
	int		offset;

	if (ray.was_hit_vertical)
		offset = fmod(ray.wall_hit.y, 1) * texture.height;
	else
		offset = fmod(ray.wall_hit.x, 1) * texture.width;
	return (offset);
}

int	find_y_offset(int wall_strip_height, int y, int height_texture)
{
	int		distance_from_top;
	int		offset;

	distance_from_top = y + (wall_strip_height / 2) - (WIN_HEIGHT / 2);
	offset = distance_from_top * ((float)height_texture / wall_strip_height);
	return (offset);
}

void	display_texture(int wall_strip_height, t_data *data,
		t_img texture, int i)
{
	int			y;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
	char		*color;
	t_position	offset;

	wall_top_pixel = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	offset.x = find_x_offset(data->rays[i], texture);
	wall_bottom_pixel = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
	if (wall_bottom_pixel > WIN_HEIGHT)
		wall_bottom_pixel = WIN_HEIGHT;
	y = wall_top_pixel;
	while (y < wall_bottom_pixel)
	{
		offset.y = find_y_offset(wall_strip_height, y, texture.height);
		color = texture.adrr + (int)(offset.y * texture.line_len
				+ offset.x * (texture.bpp / 8));
		img_pix_put(&data->img, i, y, *(unsigned int *)color);
		y++;
	}
}	

void	render_texture(int wall_strip_height, t_data *data, int i)
{
	if (data->rays[i].hit_north)
		display_texture(wall_strip_height, data, data->textures.north, i);
	else if (data->rays[i].hit_south)
		display_texture(wall_strip_height, data, data->textures.south, i);
	else if (data->rays[i].hit_west)
		display_texture(wall_strip_height, data, data->textures.west, i);
	else if (data->rays[i].hit_east)
		display_texture(wall_strip_height, data, data->textures.east, i);
}

void	render_3d(t_data *data)
{
	float	project_wall_height;
	float	perp_distance;
	int		wall_strip_height;
	int		i;

	i = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = data->rays[i].distance
			* cosf(data->rays[i].angle - data->player.rotation_angle);
		project_wall_height = (TILE_SIZE / (perp_distance * TILE_SIZE))
			* DIST_PROJ_PLANE;
		wall_strip_height = (int)project_wall_height;
		render_texture(wall_strip_height, data, i);
		i++;
	}
}
