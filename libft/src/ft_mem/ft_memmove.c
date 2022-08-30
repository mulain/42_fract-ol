/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:45:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/16 14:45:50 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memmove() function copies n bytes from memory area src to
memory area dest.
The memory areas may overlap: copying takes
place as though the bytes in src are first copied into a
temporary array that does not overlap src or dest, and the bytes
are then copied from the temporary array to dest.
The memmove() function returns a pointer to dest.
Tester: apparently this function is guarded, failed test case without guarding...
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p;
	char	*q;

	if (!dest && !src)
		return (NULL);
	p = (char *) dest;
	q = (char *) src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			p[n - 1] = q[n - 1];
			n--;
		}
	}	
	return (dest);
}
