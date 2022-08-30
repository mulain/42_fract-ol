/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:13:47 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/18 19:33:43 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsignedint(unsigned int c)
{
	int	prints;

	prints = 1;
	if (c >= 10)
		prints += ft_printint(c / 10);
	c = c % 10 + 48;
	write(1, &c, 1);
	return (prints);
}
