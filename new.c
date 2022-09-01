/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/01 18:51:58 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/*
var a = map(x, 0, width, -2, 2);
var b = map(y, 0 height, -2, 2);
*/
int	mandelbrot(int x, int y)
{
	int		n;
	int		max;
	float	a_next;
	float	b_next;
	float	a;
	float	b;

	n = 0;
	max = 50;
	a = x;
	b = y;
	while (n < max)
	{
		a_next = a * a - b * b;
		b_next = 2 * a * b;

		a = a_next + a;
		b = b_next + b;

		if ((a + b) > 16)
			break ;
		n++;
	}

	if (n == max)

	z = z * z + c;
	a = x * x - y * y
	b = 2 * x * y + c

	 abs()

}