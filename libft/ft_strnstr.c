/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:54:43 by majacque          #+#    #+#             */
/*   Updated: 2021/10/21 21:06:37 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	to_findlen;

	to_findlen = ft_strlen(to_find);
	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (*str && (i + to_findlen) <= len)
	{
		if (!ft_strncmp(str, to_find, to_findlen))
			return ((char *)str);
		str++;
		i++;
	}
	return (NULL);
}
