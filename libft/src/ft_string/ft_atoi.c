/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:08:03 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/21 21:08:03 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The atoi() function converts the initial portion of the string pointed to by
nptr to int. The behavior is the same as strtol(nptr, NULL, 10);
except that atoi() does not detect errors.
Return Value: The converted value.
*/
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		++i;
	if (nptr[i] == 45 || nptr[i] == 43)
	{	
		if (nptr[i] == 45)
			sign = -1;
		++i;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		num = num * 10 + (nptr[i] - 48);
		++i;
	}
	return (num * sign);
}
