/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:44:55 by wmardin           #+#    #+#             */
/*   Updated: 2022/01/31 23:44:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memcpy() function copies n bytes from memory area src to memory area dest.
The memory areas must not overlap. Use memmove(3) if the memory areas do 
overlap.
The memcpy() function returns a pointer to dest.
Tester: Apparently function is guarded, test case passed after guarding...
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*q;

	if (!dest && !src)
		return (NULL);
	i = 0;
	p = (char *) dest;
	q = (char *) src;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (dest);
}
