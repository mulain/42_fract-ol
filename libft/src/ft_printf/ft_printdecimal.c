/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:49:32 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:16:22 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Exact copy of ft_printint because %i and %d have same behavior
in printf base 10. Made this copied function in case I want to do bonus and
that might need different functions for i and d.
*/

int	ft_printdecimal(int c)
{
	int	prints;

	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	prints = 1;
	if (c < 0)
	{
		write(1, "-", 1);
		prints++;
		c = -c;
	}
	if (c >= 10)
		prints += ft_printdecimal(c / 10);
	c = c % 10 + 48;
	write(1, &c, 1);
	return (prints);
}
