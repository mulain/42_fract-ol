/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:36:13 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/14 21:29:06 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
return: none
Adds the node ’new’ at the beginning of the list.
Misleading formulation imo. It MOVES the node new to the
beginning of the list. New already exists.

**lst points to the pointer which points 
to the first element of the list.
**lst never changes, only the pointer it references
is changed.

temp = NULL		If lst is NULL, temp would be uninitialized,
				so it must be initialized here. 
if (lst)		if lst is not NULL
	temp = *lst	assign temp the address pointed to by **lst
				temp now corresponds to the old first link of the list
				which is therefore now pointed to twice
*lst = new;		**lst (which is never directly manipulated)
				now points to the pointer of the new link.
				the old first link is only pointed to by temp now
new->next = temp;	new now links to the old first element. it is
				now linked to twice, but temp will cease to exist
				after this function terminates.				
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = NULL;
	if (lst)
		temp = *lst;
	*lst = new;
	new->next = temp;
}
