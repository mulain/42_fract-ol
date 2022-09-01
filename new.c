/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/01 22:26:27 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/*
Zn1 = Zn0 * Zn0 + c
*/
int	mandelbrot(int x, int y, int height, int width)
{
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	int		n;
	int		n_max;
	int		set;
	double	temp;

	set = 1;
	r_min = -2.0;
	r_max = 1.0;
	i_min = -1.5;
	i_max = i_min + (r_max - r_min) * height / width;
	cr = r_min + x * (r_max - r_min) / width;
	ci = i_min + y * (i_max - i_min) / height;
	n = 0;
	zr = 0;
	zi = 0;
	n_max = 50;
	while (n < n_max)
	{
		if (zr * zr + zi * zi > 4)
		{
			set = 0;
			break ;
		}
		temp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
		n++;
	}
	return (set);
}

/*
var a = map(x, 0, width, -2, 2);
var b = map(y, 0 height, -2, 2);
*/
int	mandelnoob(int x, int y)
{
	int		n;
	int		max;
	int		a_next;
	int		b_next;
	int		a;
	int		b;

	n = 0;
	max = 20;
	a = x;
	b = y;
	while (n < max)
	{
		a_next = a * a - b * b;
		b_next = 2 * a * b;

		a = a_next + x;
		b = b_next + y;

		if (abs(a + b) > 2000000000)
			break ;
		n++;
	}
	//ft_printf("n:%i\n", n);
	return (0x00FFFFFF & 0x00000FFF<<n);
}