/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_nav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:44:02 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/13 13:50:29 by wmardin          ###   ########.fr       */
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
	if (zoom_in)
	{
		e->x_min += (e->x_mappd - e->x_min) * e->zoomfactor;
		e->x_max -= (e->x_max - e->x_mappd) * e->zoomfactor;
		e->y_min += (e->y_mappd - e->y_min) * e->zoomfactor;
		e->y_max -= (e->y_max - e->y_mappd) * e->zoomfactor;
	}
	else
	{
		e->x_min -= (e->x_mappd - e->x_min) * e->zoomfactor;
		e->x_max += (e->x_max - e->x_mappd) * e->zoomfactor;
		e->y_min -= (e->y_mappd - e->y_min) * e->zoomfactor;
		e->y_max += (e->y_max - e->y_mappd) * e->zoomfactor;
	}
	e->r_min = 2 * e->y_range / e->img_height;
	e->line = e->y_range / e->img_height;
	draw_img(e);
}
