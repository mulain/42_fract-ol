/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:17:24 by wmardin           #+#    #+#             */
/*   Updated: 2022/03/30 12:17:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function appends the null-terminated string src to the
string dest, copying at most size-strlen(dest)-1 from src, and
adds a terminating null byte to the result, unless size is less
than strlen(dest) or size is 0.  This function fixes the buffer overrun
problem of strcat(), but the caller must still handle the
possibility of data loss if size is too small.  The function
returns the length of the string strlcat() tried to create; if
the return value is greater than or equal to size, data loss
occurred.  If data loss matters, the caller must either check the
arguments before the call, or test the function return value.
strlcat() is not present in glibc and is not standardized by
POSIX, but is available on Linux via the libbsd library.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)

{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0 || size < len_dst)
		return (size + len_src);
	while (len_dst + i < size - 1 && i < len_src)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_dst + len_src);
}
