/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 12:44:39 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Zn_1 = Zn_0 * Zn_0 + c
*/
int	mandelbrot(t_env *e)
{
	int		n;
	double	x;
	double	y;
	double	temp;

	n = 0;
	x = 0;
	y = 0;
	while (n < e->iter)
	{
		if (x * x + y * y > 4)
			return (colorizer(e, n));
		temp = 2 * x * y + e->y_mappd;
		x = x * x - y * y + e->x_mappd;
		y = temp;
		n++;
	}
	return (0);
	//return (dickbutt);
}

int	julia(t_env *e)
{
	int		n;
	double	x;
	double	y;
	double	temp;

	n = 0;
	x = e->x_mappd;
	y = e->y_mappd;
	while (n < e->iter)
	{
		if (x * x + y * y > 4)
			return (colorizer(e, n));
		temp = 2 * x * y + e->julia_y;
		x = x * x - y * y + e->julia_x;
		y = temp;
		n++;
	}
	return (0);
	//return (dickbutt);
}


int	mandelnoob(t_env *e)
{
	int			n;
	double		x_next;
	double		y_next;
	double		x;
	double		y;

	x = e->x_mappd;
	y = e->y_mappd;
	n = 0;
	while (n < e->max_iter)
	{
		x_next = x * x - y * y;
		y_next = 2 * x * y;
		x = x_next + x;
		y = y_next + y;
		if (x * x - y * y > 200)
			return (colorizer(e, n));
		n++;
	}
	return (0x000000099);
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
	return (1);
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
