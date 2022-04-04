/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:53:22 by majacque          #+#    #+#             */
/*   Updated: 2022/04/04 14:33:25 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

static bool	__is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static int	__find_player(t_map *map)
{
	int	i;
	int	j;
	bool	is_player;

	is_player = false;
	i = -1;
	while (++i < map->height)
	{
		j = -0;
		while (++j < map->widht)
		{
			if (is_player == true && __is_player(map->matrix[i][j]))
				return (error_parsing("A map need to have only 1 player"));
			else if (__is_player(map->matrix[i][j]))
			{
				is_player = true;
				map->player_pos_x = j;
				map->player_pos_y = i;
			}
		}
	}
	if (is_player == false)
		return (error_parsing("Missing the player"));
	return (0);
}

static char	**__alloc_matrix(t_map *map)
{
	char	**matrix;
	int		i;

	matrix = ft_calloc(map->height, sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		matrix[i] = ft_calloc(map->widht, sizeof(char));
		if (!matrix[i])
		{
			clear_map(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

static int	__is_map_valid(t_map *map, char **matrix_check, int x, int y)
{
	if (x == 0 || x == map->widht || y == 0 || y == map->height)
		return (error_parsing("Map not surrounded by walls"));
	if (map->matrix[y][x] != '0' && !__is_player(map->matrix[y][x]))
		return (error_parsing("Invalid character in map"));
	matrix_check[y][x] = 1;
	if (map->matrix[y - 1][x] != '1' && !matrix_check[y - 1][x])
		if (__is_map_valid(map, matrix_check, x, y - 1))
			return (1);
	if (map->matrix[y + 1][x] != '1' && !matrix_check[y + 1][x])
		if (__is_map_valid(map, matrix_check, x, y + 1))
			return (1);
	if (map->matrix[y][x - 1] != '1' && !matrix_check[y][x - 1])
		if (__is_map_valid(map, matrix_check, x - 1, y))
			return (1);
	if (map->matrix[y][x + 1] != '1' && !matrix_check[y][x + 1])
		if (__is_map_valid(map, matrix_check, x + 1, y))
			return (1);
	return (0);
}

int	check_map(t_map *map)
{
	char	**matrix_check;

	if (__find_player(map))
		return (1);
	matrix_check = __alloc_matrix(map);
	if (!matrix_check)
		return (error_parsing("Ft_calloc failed"));
	if (__is_map_valid(map, matrix_check, map->player_pos_x, map->player_pos_y))
		return (1);
	clear_map(matrix_check, map->height);
	return (0);
}
