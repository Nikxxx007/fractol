/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:58:55 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 18:58:56 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*nod;

	new_list = 0;
	while (lst && f)
	{
		nod = ft_lstnew(f(lst->content));
		if (!nod)
		{
			ft_lstclear(&nod, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, nod);
		lst = lst->next;
	}
	return (new_list);
}
