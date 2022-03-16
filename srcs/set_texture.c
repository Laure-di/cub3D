/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:21:47 by majacque          #+#    #+#             */
/*   Updated: 2022/03/15 19:00:34 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/texture_lookup.h"

// TODO verify the size of imported images
int	set_north(t_data *data, char *line)
{
	char	*filename;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for north texture\n\
		Usage: \"NO <file>.xpm\""));
	}
	data->textures.north.ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&data->textures.north.width, &data->textures.north.height);
	free(filename);
	if (!data->textures.north.ptr)
		return (error_parsing("Failed to import north texture"));
	return (0);
}

int	set_south(t_data *data, char *line)
{
	char	*filename;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for south texture\n\
		Usage: \"SO <file>.xpm\""));
	}
	data->textures.south.ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&data->textures.south.width, &data->textures.south.height);
	free(filename);
	if (!data->textures.south.ptr)
		return (error_parsing("Failed to import south texture"));
	return (0);
}

int	set_east(t_data *data, char *line)
{
	char	*filename;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for east texture\n\
		Usage: \"EA <file>.xpm\""));
	}
	data->textures.east.ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&data->textures.east.width, &data->textures.east.height);
	free(filename);
	if (!data->textures.east.ptr)
		return (error_parsing("Failed to import east texture"));
	return (0);
}

int	set_west(t_data *data, char *line)
{
	char	*filename;

	line += 2;
	filename = ft_strtrim(line, " ");
	if (!filename)
		return (error_parsing("ft_strtrim failed"));
	if (check_extension(filename, ".xpm"))
	{
		free(filename);
		return (error_parsing("Wrong file extension for west texture\n\
		Usage: \"WE <file>.xpm\""));
	}
	data->textures.west.ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename,
			&data->textures.west.width, &data->textures.west.height);
	free(filename);
	if (!data->textures.west.ptr)
		return (error_parsing("Failed to import west texture"));
	return (0);
}
