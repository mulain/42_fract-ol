/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/04 01:24:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Zn_1 = Zn_0 * Zn_0 + c
*/
int	mandelbrot(t_env *e)
{
	double	x;
	double	y;
	int		n;
	double	temp;

	n = 0;
	x = 0;
	y = 0;
	while (n < e->max_iter)
	{
		if (x * x + y * y > 4)
			return (0x00000000);
		temp = 2 * x * y + e->y_mappd;
		x = x * x - y * y + e->x_mappd;
		y = temp;
		n++;
	}
	return (0x00FFFFFF & 0x00000FFF<<n);
	//return (colorizer(e, n));
}

int	mandelnoob(t_env *e)
{
	int		n;
	int		x_next;
	int		y_next;
	int		a;
	int		b;

	n = 0;
	while (n < e->max_iter)
	{
		x_next = e->x_mappd * e->x_mappd - e->y_mappd * e->y_mappd;
		y_next = 2 * e->x_mappd * e->y_mappd;

		a = x_next + e->x_mappd;
		b = y_next + e->y_mappd;

		if (abs(a + b) > 2000000000)
			break ;
		n++;
	}
	//ft_printf("n:%i\n", n);
	return (0x00FFFFFF & 0x00000FFF<<n);
}

int	mandelnoob_save(int x, int y)
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

/*
Draws the Sierpinski Triangle - but using circles!
*/
int	sierpcircle(t_env *e, int x, int y, int r)
{
	double		factor;

	factor = 1;
	if (r > 10)
	{
		sierpcircle(e, x - r * factor, y, r / 2);
		sierpcircle(e, x + r * factor, y, r / 2);
		sierpcircle(e, x, y + r * factor, r / 2);
	}
	put_circle(e, x, y, r);
	return(1);
}

int	sierpcircle_weird(t_env *e, int x, int y, int r)
{
	double		factor;

	factor = 0.66;
	if (r > 5)
	{
		sierpcircle_weird(e, x - r * factor, y, r / 2);
		sierpcircle_weird(e, x + r * factor, y, r / 2);
		sierpcircle_weird(e, x, y + r * factor, r / 2);
		//serpcircle_weird(e, x, y - r * factor, r / 2);
	}
	put_circle_weird(e, x, y, r);
	return(1);
}
