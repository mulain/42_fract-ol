/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:21:28 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:46:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: The string on which to iterate.
f: The function to apply to each character.
returns: The string created from the successive applications
of ’f’. Returns NULL if the allocation fails.
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	out = ft_strdup(s);
	if (!out)
		return (NULL);
	while (out[i])
	{
		out[i] = f(i, out[i]);
		i++;
	}
	return (out);
}
