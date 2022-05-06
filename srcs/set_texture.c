/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:21:47 by majacque          #+#    #+#             */
/*   Updated: 2022/05/06 12:59:34 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/texture_lookup.h"

// TODO verify the size of imported images
int	set_north(t_data *data, char *line)
{
	char			*filename;
	t_img *const	img = &data->textures.north;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for north texture"));
	}
	img->ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&img->width, &img->height);
	free(filename);
	if (!img->ptr)
		return (error_parsing("Failed to import north texture"));
	img->adrr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->adrr)
	{
		mlx_destroy_image(data->mlx_ptr, img->ptr);
		return (error_parsing("Failed to import infos about north texture"));
	}
	return (0);
}

int	set_south(t_data *data, char *line)
{
	char	*filename;
	t_img *const	img = &data->textures.south;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for south texture"));
	}
	img->ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&img->width, &img->height);
	free(filename);
	if (!img->ptr)
		return (error_parsing("Failed to import south texture"));
	img->adrr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->adrr)
	{
		mlx_destroy_image(data->mlx_ptr, img->ptr);
		return (error_parsing("Failed to import infos about south texture"));
	}
	return (0);
}

int	set_east(t_data *data, char *line)
{
	char	*filename;
	t_img *const	img = &data->textures.east;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for east texture"));
	}
	img->ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&img->width, &img->height);
	free(filename);
	if (!img->ptr)
		return (error_parsing("Failed to import east texture"));
	img->adrr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->adrr)
	{
		mlx_destroy_image(data->mlx_ptr, img->ptr);
		return (error_parsing("Failed to import infos about east texture"));
	}
	return (0);
}

int	set_west(t_data *data, char *line)
{
	char	*filename;
	t_img *const	img = &data->textures.west;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for west texture"));
	}
	img->ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&img->width, &img->height);
	free(filename);
	if (!img->ptr)
		return (error_parsing("Failed to import west texture"));
	img->adrr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->adrr)
	{
		mlx_destroy_image(data->mlx_ptr, img->ptr);
		return (error_parsing("Failed to import infos about west texture"));
	}
	return (0);
}
