/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:31:09 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:18:33 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_lower(unsigned int c)
{
	int	prints;

	prints = 1;
	if (c >= 16)
		prints += ft_printhex_lower(c / 16);
	c %= 16;
	write(1, &"0123456789abcdef"[c], 1);
	return (prints);
}
