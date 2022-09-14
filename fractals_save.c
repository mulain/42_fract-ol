/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:35:29 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/14 15:18:43 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	sierphelper_slow(t_env *e, double r, double x, double y)
{
	double		delta;

	if (r > e->r_min)
	{
		sierphelper_slow(e, r / 2, x - r * e->factor, y);
		sierphelper_slow(e, r / 2, x + r * e->factor, y);
		sierphelper_slow(e, r / 2, x, y + r * e->factor);
	}
	if ((e->x_mappd > x - r - e->line && e->x_mappd < x + r + e->line)
		&& (e->y_mappd > y - r - e->line
			&& e->y_mappd < y + r + e->line))
	{
		delta = (e->x_mappd - x) * (e->x_mappd - x)
			+ (e->y_mappd - y) * (e->y_mappd - y) - r * r;
		if (delta < r * e->line && delta > -(r * e->line))
			e->in_sierp = 1;
	}
}

/*
Draws the Sierpinski Triangle - but using circles!
This version works with pixel by pixel calculation, but
is insanely slow because of it.
*/
int	sierpcircle_slow(t_env *e)
{
	e->in_sierp = 0;
	sierphelper_slow(e, e->r_start, 0, 0);
	if (e->in_sierp)
		return (0x00FFFFFF);
	return (0);
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
