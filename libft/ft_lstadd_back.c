/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:05:14 by majacque          #+#    #+#             */
/*   Updated: 2021/11/20 08:40:13 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new_elem)
{
	t_list	*lst;

	lst = *alst;
	if (!*alst)
	{
		*alst = new_elem;
		return ;
	}
	if (!new_elem)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = new_elem;
}
