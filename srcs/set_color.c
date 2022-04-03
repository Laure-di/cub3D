/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:23:29 by majacque          #+#    #+#             */
/*   Updated: 2022/04/03 14:32:38 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/texture_lookup.h"

static int	__get_rgb_value(char *line)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	if (!ft_isdigit(line[i]))
		return (-1);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (i > 3)
		return (-1);
	value = ft_atoi(&line[i]);
	if (value > 255)
		return (-1);
	return (value);
}

static int	__get_color(char *str, int *value)
{
	int	r;
	int	g;
	int	b;

	r = __get_rgb_value(str);
	if (r == -1)
		return (1);
	while (ft_isdigit(*str))
		str++;
	str++;
	g = __get_rgb_value(str);
	if (g == -1)
		return (1);
	while (ft_isdigit(*str))
		str++;
	str++;
	b = __get_rgb_value(str);
	if (b == -1)
		return (1);
	*value = (r << 16 | g << 8 | b);
	return (0);
}

static int	__check_format(char *str)
{
	while (*str && ft_isdigit(*str))
		str++;
	if (!*str || *str != ',')
		return (1);
	while (*str && ft_isdigit(*str))
		str++;
	if (!*str || *str != ',')
		return (1);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str)
		return (1);
	return (0);
}

int	set_floor(t_data *data, char *line)
{
	char	*rgb_value;

	line += 2;
	rgb_value = ft_strtrim(line, " ");
	if (!rgb_value)
		return (error_parsing("ft_strtrim failed"));
	if (__check_format(rgb_value)
		|| __get_color(rgb_value, &data->textures.floor_color))
		return (error_parsing("Wrong format for floor color\n\
		Usage: \"F <R>,<G>,<B>\"\nR, G and B in range {0,255}"));
	return (0);
}

int	set_ceiling(t_data *data, char *line)
{
	char	*rgb_value;

	line += 2;
	rgb_value = ft_strtrim(line, " ");
	if (!rgb_value)
		return (error_parsing("ft_strtrim failed"));
	if (__check_format(rgb_value)
		|| __get_color(rgb_value, &data->textures.ceiling_color))
		return (error_parsing("Wrong format for ceiling color\n\
		Usage: \"C <R>,<G>,<B>\"\nR, G and B in range {0,255}"));
	return (0);
}
