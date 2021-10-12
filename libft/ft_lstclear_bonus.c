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
