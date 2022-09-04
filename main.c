/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/04 18:31:44 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env		e;

	errorcheck(argc, argv);
	set_env(&e, argv);
	//sierpcircle(&e, e.img_width / 2, e.img_height / 2, 400);
	draw_img(&e);

	mlx_key_hook(e.win, keypress, &e);
	mlx_hook(e.win, 17, 0L << 0, my_exit, NULL);
	mlx_mouse_hook(e.win, mouse_action, &e);
	mlx_loop(e.mlx);
}

/*
y = 0;
	while (y < e->img_height)
	{
		x = 0;
		while (x < e->img_width)
		{
			put_pixel(&e, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
*/

/* int	main_save(int argc, char **argv)
{
	t_env		e;
	int			x;
	int			y;

	errorcheck(argc, argv);
	set_env(&e, argv);
	//sierpcircle(&e, e.img_width / 2, e.img_height / 2, 400);
	y = 0;
	while (y < e.img_height)
	{
		x = 0;
		while (x < e.img_width)
		{
			map_pxl(&e, x, y);
			if (e.f(&e))
				put_pixel(&e, x, y, 0x00FFFFFF);
			else
				put_pixel(&e, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, keypress, &e);
	mlx_hook(e.win, 17, 0L << 0, my_exit, NULL);
	mlx_loop(e.mlx);
} */