/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:47:34 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/17 10:47:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memcmp() function compares the first n bytes (each
interpreted as unsigned char) of the memory areas s1 and s2.
The memcmp() function returns an integer less than, equal to, or
greater than zero if the first n bytes of s1 is found,
respectively, to be less than, to match, or be greater than the
first n bytes of s2.
For a nonzero return value, the sign is determined by the sign of
the difference between the first pair of bytes (interpreted as
unsigned char) that differ in s1 and s2.
If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	p = (unsigned char *) b1;
	q = (unsigned char *) b2;
	i = 0;
	while (i < len)
	{
		if (p[i] != q[i])
			return (p[i] - q[i]);
		++i;
	}
	return (0);
}
