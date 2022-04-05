/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:05:20 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/05 18:52:16 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"

static int	__error(t_data *data, char const * const str)
{
	if (data->img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}

static void	__clear_data(t_data *data)
{
	if (data->textures.north.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.north.ptr);
	if (data->textures.south.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.south.ptr);
	if (data->textures.east.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.east.ptr);
	if (data->textures.west.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.west.ptr);
	clear_map(&data->map.matrix, data->map.height);

	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

static int	__data_init(t_data *data, char const * const filename)
{
	ft_bzero(data, sizeof(*data));

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (__error(data, "Mlx can't be initialize"));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (__error(data, "Can't creat a new window"));
	data->img.ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.ptr)
		return (__error(data, "Can't creat a new image"));
	data->img.adrr = mlx_get_data_addr(data->img.ptr, &data->img.bpp, &data->img.line_len, &data->img.endian);
	if (!data->img.adrr)
		return (__error(data, "Can't get data addr of the image"));
	if (parsing(data, filename))
	{
		__clear_data(data);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nWrong number of argument", STDERR_FILENO);
		return (1);
	}
	if (__data_init(&data, argv[1]))
		return (1);
	// TODO setup_game(); avec initialize player?
	launch_game(&data);
	__clear_data(&data);
	return (0);
}
