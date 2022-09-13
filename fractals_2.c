/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/13 13:44:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Draws the Sierpinski Triangle - but using circles!
*/
int	sierpcircle(t_env *e)
{
	double		r;
	/* int			n;
	double		a;
	double		b; */

	e->in_sierp = 0;
	r = e->r_start;
	/* n = 0;
	a = 0;
	b = 0; */
	sierphelper(e, r, 0, 0);
	if (e->in_sierp)
		return (0x00FFFFFF);
	return (0);
}

int	sierpcircle_help(t_env *e)
{
	double		r;
	/* int			n;
	double		a;
	double		b; */

	r = e->r_start;
	/* n = 0;
	a = 0;
	b = 0; */
	sierphelper(e, r, 0, 0);
	if (e->in_sierp)
		return (0x00FFFFFF);
	return (0);
}

void	sierphelper(t_env *e, double r, double x, double y)
{
	double		delta;
	double		factor;

	factor = 1;
	if (r > e->r_min)
	{
		if ((e->x_mappd > x - r && e->x_mappd < x + r)
			&& (e->y_mappd > y - r && e->y_mappd < y + r))
		{
			sierphelper(e, r / 2, x - r * factor, y);
			sierphelper(e, r / 2, x + r * factor, y);
			sierphelper(e, r / 2, x, y + r * factor);
		}
	}
	delta = (e->x_mappd - x) * (e->x_mappd - x)
		+ (e->y_mappd - y) * (e->y_mappd - y) - r * r;
	if (delta < r * e->line && delta > -(r * e->line))
		e->in_sierp = 1;
}

//serpcircle_weird(e, x, y - r * factor, r / 2);
int	sierpcircle_weird(t_env *e, int x, int y, int r)
{
	double		factor;

	factor = 0.66;
	if (r > 5)
	{
		sierpcircle_weird(e, x - r * factor, y, r / 2);
		sierpcircle_weird(e, x + r * factor, y, r / 2);
		sierpcircle_weird(e, x, y + r * factor, r / 2);
	}
	//put_circle_weird(e, x, y, r);
	return (1);
}

int	sierpcircle_old(t_env *e, int x, int y, int r)
{
	double		factor;

	factor = 1;
	if (r > 10)
	{
		sierpcircle_old(e, x - r * factor, y, r / 2);
		sierpcircle_old(e, x + r * factor, y, r / 2);
		sierpcircle_old(e, x, y + r * factor, r / 2);
	}
	//put_circle(e, x, y, r);
	return (1);
}