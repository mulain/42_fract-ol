/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:36:36 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:46:51 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s1: The string to be trimmed.
set: The reference set of characters to trim.
Return: value The trimmed string. NULL if the allocation fails.
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		start;
	int		end;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = len - 1;
	while (start < len && ft_strchr(set, s1[start]) != 0)
		++start;
	if (start == len)
		return (ft_calloc(1, sizeof(char)));
	while (end > 0 && ft_strrchr(set, s1[end]) != 0)
		--end;
	out = ft_calloc(end - start + 2, sizeof(char));
	if (!out)
		return (NULL);
	ft_memmove(out, s1 + start, end - start + 1);
	return (out);
}
