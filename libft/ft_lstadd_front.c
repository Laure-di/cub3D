/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:55:38 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 08:40:35 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new_elem)
{
	if (!*alst)
	{
		*alst = new_elem;
		return ;
	}
	if (!new_elem)
		return ;
	new_elem->next = *alst;
	*alst = new_elem;
}
