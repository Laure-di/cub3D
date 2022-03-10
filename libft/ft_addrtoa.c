/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:47:08 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 09:09:59 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addrtoa(uintptr_t address)
{
	const char	base[17] = "0123456789abcdef";
	char		*str;
	int			size;

	size = ft_addrlen(address);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	if (address == 0)
		str[2] = '0';
	str[size] = 0;
	while (address > 0)
	{
		size--;
		str[size] = base[address % 16];
		address /= 16;
	}
	return (str);
}
