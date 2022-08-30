/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:31:09 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:18:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int c)
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
		prints += ft_printint(c / 10);
	c = c % 10 + 48;
	write(1, &c, 1);
	return (prints);
}
