/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:04:38 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 09:09:19 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// address sous format "0x(address en hexadecimal)"
size_t	ft_addrlen(uintptr_t address)
{
	size_t	len;

	len = 2;
	if (address == 0)
		return (len + 1);
	while (address > 0)
	{
		address /= 16;
		len++;
	}
	return (len);
}
