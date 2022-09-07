/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:05:22 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 17:16:21 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_img(t_env *e)
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

int	colorizer(t_env *e, int n)
{
	int		t;
	int		r;
	int		g;
	int		b;

	//add middle gradient color
	e->mincolor_t = 0;
	e->maxcolor_t = 0;
	e->mincolor_r = 0;
	e->maxcolor_r = 255;
	e->mincolor_g = 100;
	e->maxcolor_g = 255;
	e->mincolor_b = 200;
	e->maxcolor_b = 255;
	t = (e->maxcolor_t - e->mincolor_t) * n / e->max_iter + e->mincolor_t;
	r = (e->maxcolor_r - e->mincolor_r) * n / e->max_iter + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * n / e->max_iter + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * n / e->max_iter + e->mincolor_b;
	return (t << 24 | r << 16 | g << 8 | b);
}

void	mod_iter(t_env *e, int key)
{
	if (key == KEY_W)
	{
		if (e->iter < e->max_iter)
			e->iter += e->iterstep;
	}
	else
	{
		if (e->iter > e->min_iter)
			e->iter -= e->iterstep;
	}
	draw_img(e);
}

int	pixelizer42(int x, int y)
{
	int		x_mod;
	int		y_mod;
	int		color;
	int		bckgr;

	color = 0x00FFFFFF;
	bckgr = 0x00000000;

	x_mod = calc_absolute_int(x % 9);
	y_mod = calc_absolute_int(y % 9);
	//x_mod = x % 9;
	//y_mod = y % 9;

	if (y_mod == 0 || x_mod == 0 || y_mod == 1 || x_mod == 1)
		return (bckgr);
	if (x_mod > 0 && y_mod > 0)
		return (pixelizer42_top_r(x_mod, y_mod));

	if (x_mod == 2)
	{
		if (y_mod == 2 || y_mod == 3 || y_mod == 4 || y_mod == 5)
			return (color);
		return (bckgr);
	}
	if (x_mod == 3)
	{
		if (y_mod == 5)
			return (color);
		return (bckgr);
	}
	if (x_mod == 4)
		return (color);
	if (x_mod == 5)
		return (bckgr);
	if (x_mod == 6)
	{
		if (y_mod == 3 || y_mod == 4)
			return (bckgr);
		return (color);
	}
	if (x_mod == 7)
	{
		if (y_mod == 2 || y_mod == 5 || y_mod == 8)
			return (color);
		return (bckgr);
	}
	if (x_mod == 8)
	{
		if (y_mod == 6 || y_mod == 7)
			return (bckgr);
		return (color);
	}
	printf("x_mod:%i\n", x_mod);
	return (0x0000FFFF);
}

int	pixelizer(int x, int y)
{
	//printf("x:%i\n", x);
	//printf("y:%i\n", y);
	if (y == 0 || x == 0)
		return (0x00000000);
	if (y % 8 == 0 || x % 8 == 0)
		return (0x00000000);
	return (0x00FFFFFF);
}