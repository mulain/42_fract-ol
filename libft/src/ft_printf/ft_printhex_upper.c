/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:31:09 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:18:38 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_upper(unsigned int c)
{
	int		prints;

	prints = 1;
	if (c >= 16)
		prints += ft_printhex_upper(c / 16);
	c %= 16;
	write(1, &"0123456789ABCDEF"[c], 1);
	return (prints);
}
