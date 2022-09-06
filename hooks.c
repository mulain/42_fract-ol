/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/05 15:31:16 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyhook(int key, t_env *e)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		my_exit(0);
	}
	if (key == KEY_LEFT || key == KEY_UP || key == KEY_RIGHT || key == KEY_DOWN)
		move(e, key);
	if (key == KEY_W || key == KEY_S)
		mod_iter(e, key);
	ft_printf("key:%i\n", key);
	return (0);
}

/*
Left mousebutton: 1		-> Zoom in
Right mousebutton: 2	-> Zoom out (on Linux this is middle button)
Middle mousebutton: 3	-> No action (on Linux this is right button)
Scroll up: 5			-> Zoom in
Scroll down: 4			-> Zoom out
Scroll left: 7			-> No action
Scroll right: 6			-> No action
*/
int	mousehook(int button, int mouse_x, int mouse_y, t_env *e)
{
	e->mouse_x = mouse_x;
	e->mouse_y = mouse_y;
	e->mouse_button = button;
	if (button == 1 || button == 5)
		zoom(e, 1);
	if (button == 2 || button == 4)
		zoom(e, 0);
	return (0);
}
