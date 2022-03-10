/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:46:56 by majacque          #+#    #+#             */
/*   Updated: 2021/10/21 21:07:17 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen)
		dest = ft_calloc(sizeof(char), (slen + 1));
	else
		dest = ft_calloc(sizeof(char), (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (slen >= start)
	{
		while (s[start] && i < len)
			dest[i++] = s[start++];
	}
	return (dest);
}
