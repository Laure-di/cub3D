/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 08:54:09 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 08:57:06 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nb)
{
	size_t			len;
	unsigned int	u_nb;

	if (nb < 0)
		u_nb = -nb;
	else
		u_nb = nb;
	len = 0;
	if (nb <= 0)
		len++;
	while (u_nb > 0)
	{
		u_nb /= 10;
		len++;
	}
	return (len);
}
