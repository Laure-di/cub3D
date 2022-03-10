/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:08:07 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 07:32:05 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr_fd(int n, const char *s, int fd)
{
	int	len;

	if (!s || n < 0)
		return (0);
	len = ft_strlen(s);
	if (len < n)
		return (write(fd, s, len));
	else
		return (write(fd, s, n));
}
