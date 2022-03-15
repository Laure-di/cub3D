/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:55:50 by majacque          #+#    #+#             */
/*   Updated: 2022/03/15 18:49:07 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	parsing(t_data *data, char const *const filename)
{
	int	fd;

	if (check_extension(filename, ".cub"))
		return (error_parsing("Bad extension file"));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_parsing("Open failed"));
	if (get_textures(data, filename, fd))
	{
		close(fd);
		return (1);
	}
	// TODO scan the map
	close(fd);
	// TODO get the map
	// TODO check the map
	return (0);
}
