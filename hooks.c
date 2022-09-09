/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/09 15:37:37 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_release(int key, t_env *e)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (key == KEY_LEFT || key == KEY_UP || key == KEY_RIGHT || key == KEY_DOWN)
		move(e, key);
	if (key == KEY_W || key == KEY_S)
		mod_iter(e, key);
	if (key == KEY_I)
		mod_inside_set(e);
	if (key == KEY_C)
		mod_color(e);
	ft_printf("key:%i\n", key);
	return (0);
}

int	mouse_press(int button, int mouse_x, int mouse_y, t_env *e)
{
	if (button == MOUSE_LEFT)
	{
		e->mouse_x = mouse_x;
		e->mouse_y = mouse_y;

	}
	calc_xyranges(e);
	map_pxl(e, mouse_x, mouse_y);
	if (/* button == MOUSE_LEFT || */ button == MOUSE_SCR_UP)
		zoom(e, 1);
	if (button == MOUSE_RIGHT || button == MOUSE_SCR_DOWN)
		zoom(e, 0);
	return (0);
}

int	mouse_release(int button, int mouse_x, int mouse_y, t_env *e)
{
	int		x;
	int		y;

	printf("hello\n");
	if (button != MOUSE_LEFT)
	{
		printf("hello\n");
		return (0);
	}
	x = e->mouse_x;
	y = e->mouse_y;
	x = x - mouse_x;
	y = y - mouse_y;
	e->x_max += (double)x / (double)e->img_width * e->x_range;
	e->x_min += (double)x / (double)e->img_width * e->x_range;
	e->y_max += (double)y / (double)e->img_height * e->y_range;
	e->y_min += (double)y / (double)e->img_height * e->y_range;
	draw_img(e);
	return (1);
}
