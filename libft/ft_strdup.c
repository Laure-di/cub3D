/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:41:38 by majacque          #+#    #+#             */
/*   Updated: 2021/10/21 21:04:24 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len_src;

	len_src = ft_strlen(src);
	dest = malloc(sizeof(char) * (len_src + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, (len_src + 1));
	return (dest);
}
