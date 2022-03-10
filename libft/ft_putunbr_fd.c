/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:36:42 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 07:31:55 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	static int	ret = 0;

	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	return (ret += ft_putchar_fd((n % 10) + '0', fd));
}
