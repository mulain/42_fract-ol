/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_nav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:44:02 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/09 15:51:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_key(t_env *e, int key)
{
	double		movestep;

	calc_xyranges(e);
	movestep = e->y_range * e->movefactor;
	if (key == KEY_LEFT)
	{
		e->x_max -= movestep;
		e->x_min -= movestep;
	}
	if (key == KEY_RIGHT)
	{
		e->x_min += movestep;
		e->x_max += movestep;
	}
	if (key == KEY_UP)
	{
		e->y_min -= movestep;
		e->y_max -= movestep;
	}
	if (key == KEY_DOWN)
	{
		e->y_min += movestep;
		e->y_max += movestep;
	}
	draw_img(e);
}

void	move_mouse(t_env *e)
{
	double		x_delta;
	double		y_delta;

	x_delta = e->mouse_press_x - e->mouse_release_x;
	y_delta = e->mouse_press_y - e->mouse_release_y;
	e->x_max += x_delta / e->img_width * e->x_range;
	e->x_min += x_delta / e->img_width * e->x_range;
	e->y_max += y_delta / e->img_height * e->y_range;
	e->y_min += y_delta / e->img_height * e->y_range;
	draw_img(e);
}

void	zoom(t_env *e, int zoom_in)
{
	double		delta_x;
	double		delta_y;
	double		factor;

	factor = 0.33;
	calc_xyranges(e);
	delta_x = e->x_mappd - (e->x_min + e->x_max) / 2;
	delta_y = e->y_mappd - (e->y_min + e->y_max) / 2;
	if (zoom_in)
	{
		e->x_min += e->x_range * e->zoomfactor + delta_x * factor;
		e->x_max -= e->x_range * e->zoomfactor - delta_x * factor;
		e->y_min += e->y_range * e->zoomfactor + delta_y * factor;
		e->y_max -= e->y_range * e->zoomfactor - delta_y * factor;
	}
	else
	{
		e->x_min -= e->x_range * e->zoomfactor - delta_x * factor;
		e->x_max += e->x_range * e->zoomfactor + delta_x * factor;
		e->y_min -= e->y_range * e->zoomfactor - delta_y * factor;
		e->y_max += e->y_range * e->zoomfactor + delta_y * factor;
	}
	draw_img(e);
}
