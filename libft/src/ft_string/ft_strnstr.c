/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:01:29 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/17 11:01:29 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strnstr() function locates the	first occurrence of the	null-termi-
nated string little in the	string big, where not more than	len characters
are searched.  Characters that appear after a `\0'	character are not
searched. Since the strnstr() function is a FreeBSD specific API, it
should only be used when portability is not a concern.
If little is an empty string, big is returned; if little occurs nowhere
in big, NULL is returned; otherwise a pointer to the first character of
the first occurrence of little is returned.

Line 40: Tester requires SegFault when NULL pointer is given
this makes it happen...
(it wouldn't happen in some cases where the while loop never starts
because len is too small thus not operating the Null pointer.)
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *) big);
	i = 0;
	while (big[0] == little[0])
		break ;
	while (i + len_little <= len && big[i])
	{
		if (ft_strncmp(big + i, little, len_little) == 0)
			return ((char *)big + i);
		++i;
	}
	return (NULL);
}
