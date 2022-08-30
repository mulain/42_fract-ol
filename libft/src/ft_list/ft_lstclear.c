/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:28:08 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/10 21:06:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
lst: The address of a pointer to a node.
del: The address of the function used to delete
the content of the node.
return: none.
Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp1;
	t_list	*temp2;

	if (!lst || !del)
		return ;
	temp1 = *lst;
	while (temp1->next)
	{
		temp2 = temp1->next;
		ft_lstdelone(temp1, del);
		temp1 = temp2;
	}
	ft_lstdelone(temp1, del);
	*lst = NULL;
}
