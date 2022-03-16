/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:55:50 by majacque          #+#    #+#             */
/*   Updated: 2022/03/16 19:55:44 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	parsing(t_data *data, char const *const filename)
{
	int	fd;

	if (check_extension(filename, ".cub"))
		return (error_parsing("Wrong file extension, should be <file>.cub"));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_parsing("Open failed"));
	if (get_textures(data, filename, fd) || get_infos_map(data, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_parsing("Open failed"));
	// TODO get the map
	close(fd);
	// TODO check the map
	return (0);
}
