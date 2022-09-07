/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:05:22 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 13:08:33 by wmardin          ###   ########.fr       */
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
