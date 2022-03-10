/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:27:06 by majacque          #+#    #+#             */
/*   Updated: 2021/10/21 21:06:56 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	len;

	len = ft_strlen(to_find);
	if (!*to_find)
		return ((char *)str);
	while (*str)
	{
		if (!ft_strncmp(str, to_find, len))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
