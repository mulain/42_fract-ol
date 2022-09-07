/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:44:02 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 11:52:38 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_env *e, int key)
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

/*
printf("x_center:%f\n", x_center);
	printf("y_center:%f\n", y_center);
	printf("delta_x:%f\n", delta_x);
	printf("delta_y:%f\n", delta_y);
*/
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
