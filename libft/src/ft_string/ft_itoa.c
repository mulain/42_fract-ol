/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:13:51 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:29:51 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
n: the integer to convert.
return: The string representing the integer. NULL if the allocation fails.
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/
static int	getsize(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*makestring(char *out, int n, int i)
{
	if (n < 0)
	{
		n = -n;
		out[0] = '-';
	}
	while (n > 0)
	{
		out[i--] = n % 10 + 48;
		n /= 10;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*out;

	if (n == 0)
	{
		out = ft_strdup("0");
		if (!out)
			return (NULL);
		return (out);
	}
	if (n == -2147483648)
	{
		out = ft_strdup("-2147483648");
		if (!out)
			return (NULL);
		return (out);
	}
	i = getsize(n);
	out = ft_calloc(i + 1, sizeof(char));
	if (!out)
		return (NULL);
	makestring(out, n, i - 1);
	return (out);
}
