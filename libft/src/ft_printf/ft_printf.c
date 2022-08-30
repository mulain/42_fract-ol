/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:41:16 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:18:08 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *formatstr, ...)
{
	int			i;
	int			prints;
	va_list		args;

	if (!formatstr)
		return (0);
	i = 0;
	prints = 0;
	va_start(args, formatstr);
	while (formatstr[i])
	{
		if (formatstr[i] != '%')
			prints += ft_printchar(formatstr[i]);
		else
		{
			i++;
			prints += ft_checkformat(formatstr[i], args);
		}
		i++;
	}
	va_end(args);
	return (prints);
}
