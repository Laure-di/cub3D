/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:14:57 by majacque          #+#    #+#             */
/*   Updated: 2022/03/10 16:59:42 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atou(const char *str)
{
	unsigned int	nb;

	nb = 0;
	while (ft_iswspace(*str) == true)
		str++;
	while (ft_isdigit(*str) == true)
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb);
}
