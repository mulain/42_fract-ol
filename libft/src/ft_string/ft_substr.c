/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:14:52 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:47:15 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
- s: The string from which to create the substring.
- start: The start index of the substring in the string ’s’.
- len: The maximum length of the substring.

Return: The substring. NULL if the allocation fails.

Allocates (with malloc(3)) and returns a substring
from the string ’s’.

The substring begins at index ’start’ and is of
maximum size ’len’.

Personal Note:
Only the actually required space is calloc'd.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*out;
	unsigned int	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		out = ft_calloc(1, sizeof(char));
		if (!out)
			return (NULL);
		return (out);
	}
	if (len > len_s - start)
		out = malloc((len_s - start + 1) * sizeof(char));
	else
		out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, len + 1);
	return (out);
}
