/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:31:39 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/17 10:31:39 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memchr() function scans the initial n bytes of the memory
area pointed to by s for the first instance of c.  Both c and the
bytes of the memory area pointed to by s are interpreted as
unsigned char.
The memchr() and memrchr() functions return a pointer to the
matching byte or NULL if the character does not occur in the
given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *) s;
	i = 0;
	while (i < len)
	{
		if (p[i] == (unsigned char) c)
			return (p + i);
		++i;
	}
	return (NULL);
}
