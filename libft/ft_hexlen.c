/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:02:01 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 09:02:37 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (len + 1);
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}
