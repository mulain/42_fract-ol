/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:17:28 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/10 07:48:43 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Setting y_max:
range_y = y_max - y_min
range_x = x_max - x_min
range_x / img_width = range_y / img_height
range_y = (range_x / img_width) * img_height
y_max = y_min + (range_x / img_width) * img_height

x axis is taken as fixed axis for window calculation.
x axis 0 is moved to the right for mandelbrot, therefore
x_max should be (around) 0.5 * abs(x_min)
y axis is evenly divided, therefore y min and max are half
of the range of x. but img ratio has to be taken into account
so we have to multiply that with (width/height) to not get
distorted images when using not square image dimensions.
*/
void	set_env(t_env *e, char **argv)
{
	char	fractal;

	fractal = argv[1][0];
	e->img_width = 1080;
	e->img_height = 580;
	set_color(e, argv[2][0]);
	if (fractal == 'M')
		set_mandelbrot(e);
	if (fractal == 'J')
		set_julia(e, argv[3][0]);
	if (fractal == 'B')
		set_burningship(e);
	if (fractal == 'S')
		e->fractal = sierpcircle;
	if (fractal == 'N')
	{
		e->fractal = mandelnoob;
		set_vars_brot(e);
	}
}

void	set_vars_generic(t_env *e)
{
	e->x_min = -2.0;
	e->x_max = -e->x_min;
	e->x_range = e->x_max - e->x_min;
	e->y_min = -(e->x_range) / 2 * e->img_height / e->img_width;
	e->y_max = (e->x_range) / 2 * e->img_height / e->img_width;
	e->y_range = e->y_max - e->y_min;
	calc_xyranges(e);
	e->max_iter = 260;
	e->min_iter = 60;
	e->iter = 160;
	e->iterstep = 20;
	e->zoomfactor = 0.1;
	e->movefactor = 0.1;
}

void	set_vars_brot(t_env *e)
{
	e->x_min = -2.7;
	e->x_max = e->x_min * -0.6;
	e->x_range = e->x_max - e->x_min;
	e->y_min = -(e->x_range) / 2 * e->img_height / e->img_width;
	e->y_max = (e->x_range) / 2 * e->img_height / e->img_width;
	e->y_range = e->y_max - e->y_min;
	calc_xyranges(e);
	e->max_iter = 260;
	e->min_iter = 20;
	e->iter = 100;
	e->iterstep = 20;
	e->zoomfactor = 0.3;
	e->movefactor = 0.1;
	e->inside_set = white;
}

void	set_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img_width, e->img_height, "fract'ol");
	e->img = mlx_new_image(e->mlx, e->img_width, e->img_height);
	e->img_addr = mlx_get_data_addr(e->img, &e->img_bpp, &e->img_line_length,
			&e->img_endian);
	e->img_bytespp = e->img_bpp / 8;
}
