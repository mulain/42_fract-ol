/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:05:22 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/13 16:38:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pxl(t_env *e)
{
	int		x;
	int		y;

	calc_xyranges(e);
	y = 0;
	while (y < e->img_height)
	{
		x = 0;
		while (x < e->img_width)
		{
			map_pxl(e, x, y);
			put_pixel(e, x, y, e->fractal(e));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_sierp(t_env *e)
{
	sierpcircle(e, 0, 0, e->r_start);
}

void	draw_circe(t_env *e, int a, int b, int r)
{
	int		x;
	int		y;
	int		delta;
	int		thickness;

	thickness = 1;
	y = b - r - thickness;
	if (y < 0)
		y = 0;
	while (y < b + r + thickness && y < e->img_height)
	{
		x = a - r - thickness;
		if (x < 0)
			x = 0;
		while (x < a + r + thickness && x < e->img_width)
		{
			delta = (x - a) * (x - a) + (y - b) * (y - b) - r * r;
			if (delta < r + r * thickness && delta > -(r + r * thickness))
				put_pixel(e, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	put_pixel(t_env *e, int x, int y, int color)
{
	char	*pxl;

	pxl = e->img_addr + (y * e->img_line_length + x * (e->img_bytespp));
	*(unsigned int *)pxl = color;
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
void	put_circle(t_env *e, double a, double b, double r)
{
	int		x;
	int		y;
	int		delta;
	int		thickness;

	thickness = 1;
	y = b - r - thickness;
	if (y < 0)
		y = 0;
	while (y < b + r + thickness && y < e->img_height)
	{
		x = a - r - thickness;
		if (x < 0)
			x = 0;
		while (x < a + r + thickness && x < e->img_width)
		{
			delta = (x - a) * (x - a) + (y - b) * (y - b) - r * r;
			if (delta < r + r * thickness && delta > -(r + r * thickness))
				put_pixel(e, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}
