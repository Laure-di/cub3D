/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:18:18 by majacque          #+#    #+#             */
/*   Updated: 2022/03/15 14:18:47 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	check_extension(char const *const filename, char const *const ext)
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
