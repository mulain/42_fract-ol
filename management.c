/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/04 19:14:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keypress(int key, t_env *e)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		my_exit(0);
	}
	if (key == KEY_LEFT || key == KEY_UP || key == KEY_RIGHT || key == KEY_DOWN)
		move(e, key);
	ft_printf("key:%i\n", key);
	return (0);
}

/*
Left mousebutton: 1
Right mousebutton: 2
Middle mousebutton: 3 (apple mouse doesn't have it)
Scroll up: 5
Scroll down: 4
Scroll left: 7
Scroll right: 6
*/
int	mouse_action(int button, int mouse_x, int mouse_y, t_env *e)
{
	e->mouse_x = mouse_x;
	e->mouse_y = mouse_y;
	e->mouse_button = button;
	return (0);
}

int	my_exit(int failure)
{
	if (failure)
	{
		ft_printf("Exit on error.\n");
		exit(1);
	}
	ft_printf("Exit.\n");
	exit(0);
}
