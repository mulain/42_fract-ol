/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:29:48 by wmardin           #+#    #+#             */
/*   Updated: 2022/01/30 17:29:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memset() function fills the first n bytes of the memory area
pointed to by s with the constant byte c.
The memset() function returns a pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *) s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}
