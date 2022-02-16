/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:58:40 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 18:58:41 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem_temp;

	while (*lst)
	{
		del((*lst)->content);
		elem_temp = *lst;
		*lst = elem_temp->next;
		free(elem_temp);
	}
	lst[0] = NULL;
}
