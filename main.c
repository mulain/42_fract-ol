/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/03 08:27:05 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env		e;

	if (argc < 3 || argc > 10)
		return (error_msg(argc, argv));

	e.y = 0;
	e.img_width = 1000;
	e.img_height = 1000;
	e.color = 0x00FFFFFF;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.img_width, e.img_height, "fract'ol");
	e.img = mlx_new_image(e.mlx, e.img_width, e.img_height);
	e.img_addr = mlx_get_data_addr(e.img, &e.img_bpp, &e.img_line_length,
			&e.img_endian);
	//put_rectangle(&b, 10, 10);
	//put_circle(&b, 500, 500, 200);
	sierpcircle(&e, e.img_width / 2, e.img_height / 2, 400);
	/*while (e.y < e.img_height)
	{
		e.x = 0;
		while (e.x < e.img_width)
		{
			if (mandelbrot(e.x, e.y, e.img_height, e.img_width))
				put_pixel(&b, e.x, e.y, 0x00FFFFFF);
			else
				put_pixel(&b, e.x, e.y, 0x00000000);
			e.x++;
		}
		e.y++;
	}*/
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, keypress, &e);
	mlx_hook(e.win, 17, 0L << 0, my_exit, NULL);
	mlx_loop(e.mlx);
}
