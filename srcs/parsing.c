/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:55:50 by majacque          #+#    #+#             */
/*   Updated: 2022/03/12 20:14:05 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"

static int	__error(char const *const str)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}

static int	__check_extension(char const *const filename, char const *const ext)
{
	size_t const	filename_len = ft_strlen(filename);
	size_t const	ext_len = ft_strlen(ext);

	if (filename_len <= ext_len)
		return (1);
	if (filename[filename_len - ext_len - 1] == '/')
		return (1);
	if (ft_strcmp(&filename[filename_len - ext_len], ext))
		return (1);
	return (0);
}

static int	__try_set_texture(t_data *data, char *line)
{
	// TODO try_set_texture()
	return (0);
}

static bool	__is_all_textures_set(t_texture *textures)
{
	// TODO is_all_textures_set()
	return (true);
}

static int	__get_textures(t_data *data,
							char const *const filename, int *const line_nb)
{
	int const	fd = open(filename, O_RDONLY);
	char	*line;
	int		ret;

	if (fd == -1)
		return (1);
	line = NULL;
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (1);
	*line_nb = 1;
	while (ret == 1)
	{
		if (__try_set_texture(data, line) && *line)
			break ;
		free(line);
		ret = get_next_line(fd, &line);
		(*line_nb)++;
	}
	free(line);
	close(fd);
	if (ret == -1 || !__is_all_textures_set(&data->textures))
		return (1);
	return (0);
}

int	parsing(t_data *data, char const *const filename)
{
	int	line_nb;

	if (__check_extension(filename, ".cub"))
		return (__error("Bad extension file"));
	if (__get_textures(data, filename, &line_nb))
		return (1); // TODO Error messages
	// TODO scan the map
	// TODO get the map
	// TODO check the map
	return (0);
}
