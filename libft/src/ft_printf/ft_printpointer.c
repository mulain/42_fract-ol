/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:18:05 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:23:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printlonglonghex(unsigned long long c)
{
	int	prints;

	prints = 1;
	if (c >= 16)
		prints += printlonglonghex(c / 16);
	c %= 16;
	write(1, &"0123456789abcdef"[c], 1);
	return (prints);
}

int	ft_printpointer(unsigned long long c)
{
	write (1, "0x", 2);
	return (printlonglonghex(c) + 2);
}
