/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:48:53 by majacque          #+#    #+#             */
/*   Updated: 2022/04/03 14:39:08 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_LOOKUP_H
# define TEXTURE_LOOKUP_H

# include "cub3D.h"
# include "../libft/libft.h"

typedef struct s_texture_lookup	t_texture_lookup;

struct s_texture_lookup
{
	char	*id;
	int		(*f)(t_data *, char *);
};

int	set_north(t_data *data, char *line);
int	set_south(t_data *data, char *line);
int	set_east(t_data *data, char *line);
int	set_west(t_data *data, char *line);
int	set_floor(t_data *data, char *line);
int	set_ceiling(t_data *data, char *line);

static const t_texture_lookup	g_texture_lookup[] = {
{"NO", set_north},
{"SO", set_south},
{"EA", set_east},
{"WE", set_west},
{"F ", set_floor},
{"C ", set_ceiling},
{NULL, NULL}
};

int		error_parsing(char const *const str);
int		check_extension(char const *const filename, char const *const extension);
#endif
