/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 20:55:05 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyhook(int key, t_env *e)
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
	ft_printf("key:%i\n", key);
	return (0);
}

int	mousehook(int button, int mouse_x, int mouse_y, t_env *e)
{
	calc_xyranges(e);
	map_pxl(e, mouse_x, mouse_y);
	e->mouse_button = button;
	if (button == MOUSE_LEFT || button == MOUSE_SCR_UP)
		zoom(e, 1);
	if (button == MOUSE_RIGHT || button == MOUSE_SCR_DOWN)
		zoom(e, 0);
	return (0);
}
