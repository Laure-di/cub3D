/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:00:35 by majacque          #+#    #+#             */
/*   Updated: 2021/11/16 00:37:12 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstjoin(t_list **list1, t_list *list2)
{
	t_list	*lst;

	lst = *list1;
	if (!*list1)
	{
		*list1 = list2;
		return ;
	}
	if (!list2)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = list2;
}
