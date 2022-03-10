/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:30:07 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 07:29:44 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	ret;

	if (!s)
		return (0);
	ret = write(fd, s, ft_strlen(s));
	ret += write(fd, "\n", 1);
	return (ret);
}
