/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:23:47 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 09:00:04 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int nb)
{
	char	*str;
	size_t	size;

	size = ft_uintlen(nb);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[size] = 0;
	while (nb > 0)
	{
		size--;
		str[size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
