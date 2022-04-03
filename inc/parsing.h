/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:14:07 by majacque          #+#    #+#             */
/*   Updated: 2022/04/03 14:35:42 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "texture_lookup.h"

int		error_parsing(char const *const str);
int		check_extension(char const *const filename, char const *const extension);
int		get_textures(t_data *data, int const fd, int *const nb_line_map);
int		get_infos_map(t_data *data, int fd, int *const nb_line_map);
int		get_map(t_data *data, int const fd, int nb_line_map);
int		parsing(t_data *data, char const *const filename);

void	clear_map(char **map, int height);

#endif
