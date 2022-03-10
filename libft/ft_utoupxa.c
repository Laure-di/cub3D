/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoupxa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:05:37 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 09:03:58 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoupxa(unsigned int nb)
{
	const char	base[17] = "0123456789ABCDEF";
	char		*str;
	size_t		size;

	size = ft_hexlen(nb);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[size] = 0;
	while (nb > 0)
	{
		size--;
		str[size] = base[nb % 16];
		nb /= 16;
	}
	return (str);
}
