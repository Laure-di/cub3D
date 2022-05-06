/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:28:51 by majacque          #+#    #+#             */
/*   Updated: 2022/05/06 18:37:19 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	find_x_offset(t_ray ray, t_img texture)
{
	int	offset;
	if (ray.wasHitVertical)
		offset = fmod(ray.wallHit.y, 1) * texture.height;
	else
		offset = fmod(ray.wallHit.x, 1) * texture.width;
	return (offset);
}

int	find_y_offset(int wall_strip_height, int y, int height_texture)
{
	int	distance_from_top;
	int	offset;

	distance_from_top = y + (wall_strip_height / 2) - (WIN_HEIGHT / 2);
	offset = distance_from_top * ((float)height_texture / wall_strip_height);
	return (offset);
}

void	display_texture(int wall_strip_height, t_data *data, t_img texture, t_ray ray, int i)
{
	int 		y;
	int 		wall_top_pixel;
	int		wall_bottom_pixel;
	t_offset	offset;
	char		*color;

	wall_top_pixel = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	offset.x = find_x_offset(ray, texture);
	wall_bottom_pixel = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
	if (wall_bottom_pixel > WIN_HEIGHT)
		wall_bottom_pixel = WIN_HEIGHT;
	y = wall_top_pixel;
	while (y < wall_bottom_pixel)
	{
		offset.y = find_y_offset(wall_strip_height, y, texture.height);
		//printf("y = %f, x = %f\n", offset.y, offset.x);
		color = texture.adrr + (offset.y * texture.line_len + offset.x * (texture.bpp / 8));
		img_pix_put(&data->img, i, y, *(unsigned int*)color);
		y++;
	}
}	

void	render_texture(int wall_strip_height, t_data *data, int i)
{
	if (data->rays[i].isFacingUp)
		display_texture(wall_strip_height, data, data->textures.north, data->rays[i], i);
	if (data->rays[i].isFacingDown)
		display_texture(wall_strip_height,  data, data->textures.south, data->rays[i], i);
	if (data->rays[i].isFacingLeft)
		display_texture(wall_strip_height, data, data->textures.west, data->rays[i], i);	
	if (data->rays[i].isFacingRight)
		display_texture(wall_strip_height, data, data->textures.east, data->rays[i], i);	

}

void	render_3d(t_data *data)
{
	float	project_wall_height;
	float	perp_distance;
	int		wall_strip_height;
	//int		wall_top_pixel;
	//int		wall_bottom_pixel;
	int		i;
	//int		y;

	i = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = data->rays[i].distance * cosf(data->rays[i].angle - data->player.rotationAngle);
		project_wall_height = (1 /  (perp_distance * 1)) * DIST_PROJ_PLANE;
		wall_strip_height = (int)project_wall_height;
		render_texture(wall_strip_height, data, i);

	/*	wall_top_pixel = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;

		wall_bottom_pixel = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
		if (wall_bottom_pixel > WIN_HEIGHT)
			wall_bottom_pixel = WIN_HEIGHT;

		y = wall_top_pixel;
		while (y < wall_bottom_pixel)
		{
			if (data->rays[i].wasHitVertical)
			{
				//perform offset for the vertical hit
				img_pix_put(&data->img, i, y, GOLD);
			}
			else
			{
				//perform offset for the horizontal hit
				img_pix_put(&data->img, i, y, SHADE_GOLD);
			}
			y++;
		}*/
		i++;
	}
}
