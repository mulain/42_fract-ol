/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:35:29 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/14 18:06:36 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	sierpcircle(t_env *e, int a, int b, int r)
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

/*
Draws a circle of radius r with the center coordinates of (a;b).
Variables x and y iterate through the image to check for pixels that
lie within a range of the circle's circumference. That range is defined by
thickness. The calculation of y and x is tedious in order to save computing
time: Only pixels in the square centered at (a;b) with side length
2*r + 2*thickness are investigated.
x and y should never be negative. Negative y will probably segfault. For
negative x it is more likely that the pixels that should be outside of the
frame (and not drawn at all) are bumped up into the previous line and
spill onto the opposite side of the image. Negative x in the first line will
also probaly segfault as the "previous" line will be outside of the allocated
memory area of the image. However, a sufficiently negative x value in lower lines
could jump up several lines and still segfault. Just saying.
*/
void	put_circle(t_env *e, int a, int b, int r)
{
	double		delta;
	int			y;
	int			x;

	e->a_mappd = a * e->x_range / e->img_width;
	e->b_mappd = b * e->x_range / e->img_width;
	e->r_mappd = r * e->x_range / e->img_width;
	y = b - r - e->line;
	if (y < 0)
		y = 0;
	while (y < b + r + e->line && y < e->img_height)
	{
		x = a - r - e->line;
		if (x < 0)
			x = 0;
		while (x < a + r + e->line && x < e->img_width)
		{
			map_pxl(e, x, y);
			delta = getdelta(e);
			if (delta < e->r_mappd * e->line && delta > -(e->r_mappd * e->line))
				put_pixel(e, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

/*
Calculates how much offset the coordinates (x_mappd;y_mappd) have from being
part of the circle of radius (r_mappd) and center (a_mappd;b_mappd).
Basic formula is:
x² + y² = r²
changed to
(x - a)² + (y - b)² = r²
changed to
delta = (x - a)² + (y - b)² - r²
*/
double	getdelta(t_env *e)
{
	return ((e->x_mappd - e->a_mappd) * (e->x_mappd - e->a_mappd)
		+ (e->y_mappd - e->b_mappd) * (e->y_mappd - e->b_mappd)
		- e->r_mappd * e->r_mappd);
}
