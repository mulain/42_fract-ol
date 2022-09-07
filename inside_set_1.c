/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_set_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:35:31 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 20:49:11 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	standard(int x, int y)
{
	return ((x + y) * 0);
}

int	pixelizer(int x, int y)
{
	if (y == 0 || x == 0)
		return (0x00000000);
	if (y % 8 == 0 || x % 8 == 0)
		return (0x00000000);
	return (0x00FFFFFF);
}
