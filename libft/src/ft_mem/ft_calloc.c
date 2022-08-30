/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:45:27 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:29:11 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The calloc() function allocates memory for an array of nmemb elements of size
bytes each and returns a pointer to the allocated memory. The memory is
set to zero. If nmemb or size is 0, then calloc() returns either NULL, or a
unique pointer value that can later be successfully passed to free().
The malloc() and calloc() functions return a pointer to the allocated memory
that is suitably aligned for any kind of variable. On error, these functions
return NULL. NULL may also be returned by a successful call to malloc() with a
size of zero, or by a successful call to calloc() with nmemb or size equal to
zero.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size == __SIZE_MAX__)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
