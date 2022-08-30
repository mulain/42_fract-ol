/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:53:28 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/08 20:53:28 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strchr() function returns a pointer to the first occurrence
of the character c in the string s.
The strrchr() function returns a pointer to the last occurrence
of the character c in the string s.
The strchrnul() function is like strchr() except that if c is not
found in s, then it returns a pointer to the null byte at the end
of s, rather than NULL.

Here "character" means "byte"; these functions do not work with
wide or multibyte characters.
*/
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		++i;
	}
	if (c == 0)
		return ((char *)s + i);
	return (NULL);
}
