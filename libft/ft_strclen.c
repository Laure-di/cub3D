/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:51:19 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 09:21:01 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (str[0] == '-' || str[0] == '+')
		len++;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}
