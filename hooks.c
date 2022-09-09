/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/09 15:52:57 by wmardin          ###   ########.fr       */
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
		move_key(e, key);
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
		e->mouse_press_x = mouse_x;
		e->mouse_press_y = mouse_y;
	}
	calc_xyranges(e);
	map_pxl(e, mouse_x, mouse_y);
	if (button == MOUSE_LEFT || button == MOUSE_SCR_UP)
		zoom(e, 1);
	if (button == MOUSE_RIGHT || button == MOUSE_SCR_DOWN)
		zoom(e, 0);
	return (0);
}

int	mouse_release(int button, int mouse_x, int mouse_y, t_env *e)
{
	if (button == MOUSE_LEFT)
	{
		e->mouse_release_x = mouse_x;
		e->mouse_release_y = mouse_y;
		move_mouse(e);
	}
	return (1);
}
