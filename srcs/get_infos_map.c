/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:54:57 by majacque          #+#    #+#             */
/*   Updated: 2022/04/05 18:46:52 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

static bool	__is_line_valid(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '1' && *str != '0'
			&& *str != 'N' && *str != 'S' && *str != 'E' && *str != 'W')
			return (false);
		str++;
	}
	return (true);
}

int	get_infos_map(t_data *data, int fd, int *const nb_line_map)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (error_parsing("Get_next_line failed"));
	while (ret == 1)
	{
		if (!*line && data->map.height)
		{
			free(line);
			return (error_parsing("Empty line in map"));
		}
		else if (!*line)
			(*nb_line_map)++;
		if (!__is_line_valid(line))
		{
			free(line);
			return (error_parsing("Wrong character in map"));
		}
		data->map.height++;
		if ((int)ft_strlen(line) > data->map.widht)
			data->map.widht = ft_strlen(line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	if (ret == -1)
		return (error_parsing("Get_next_line failed"));
	return (0);
}
