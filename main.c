/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/03 17:31:21 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env		e;

	errorcheck(argc, argv);
	set_env(&e, argv);
	//sierpcircle(&e, e.img_width / 2, e.img_height / 2, 400);
	e.y = 0;
	while (e.y < e.img_height)
	{
		e.x = 0;
		while (e.x < e.img_width)
		{
			if (mandelbrot(e.x, e.y, e.img_height, e.img_width))
				put_pixel(&e, e.x, e.y, 0x00FFFFFF);
			else
				put_pixel(&e, e.x, e.y, 0x00000000);
			e.x++;
		}
		e.y++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, keypress, &e);
	mlx_hook(e.win, 17, 0L << 0, my_exit, NULL);
	mlx_loop(e.mlx);
}
