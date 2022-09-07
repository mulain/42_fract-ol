/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_set_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:35:31 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 23:05:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	black(__attribute__((unused)) int x, __attribute__((unused)) int y)
{
	return (0);
}

int	white(__attribute__((unused)) int x, __attribute__((unused)) int y)
{
	return (0x00FFFFFF);
}

int	pixelizer(int x, int y)
{
	if (y == 0 || x == 0)
		return (0x00000000);
	if (y % 8 == 0 || x % 8 == 0)
		return (0x00000000);
	return (0x00FFFFFF);
}
