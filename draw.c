/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:05:22 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/13 16:22:37 by wmardin          ###   ########.fr       */
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

void	draw_circ(t_env *e)
{
	e->iter += 10;
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
