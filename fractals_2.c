/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/13 16:36:31 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	sierpcircle(t_env *e, double a, double b, double r)
{
	if (r > e->r_min)
	{
		sierpcircle(e, a - r * e->factor, b, r / 2);
		sierpcircle(e, a + r * e->factor, b, r / 2);
		sierpcircle(e, a, b + r * e->factor, r / 2);
	}
	put_circle(e, a, b, r);
	return (1);
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
