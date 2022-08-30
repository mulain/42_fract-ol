/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:54:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/03/28 20:54:14 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlcpy() function copies up to size - 1 characters
from the NUL-terminated string src to dst, NUL-terminating the result.
Strlcpy() and strlcat() return the total length of the 
string they tried to create.
For strlcpy() that means the length of src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
