/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/02 17:13:51 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_block		b;

	b.y = 0;
	b.img_width = 1000;
	b.img_height = 1000;
	b.color = 0x00FFFFFF;
	b.mlx = mlx_init();
	b.win = mlx_new_window(b.mlx, b.img_width, b.img_height, "fract-ol");
	b.img = mlx_new_image(b.mlx, b.img_width, b.img_height);
	b.img_addr = mlx_get_data_addr(b.img, &b.img_bpp, &b.img_line_length,
			&b.img_endian);

	//my_put_rectangle(&b, 10, 10);
	//my_put_circle(&b, 500, 500, 200);
	b.x = b.img_width / 2;
	b.y = b.img_height / 2;
	serpcircle(&b, b.x, b.y, 100);
	/* while (b.y < b.img_height)
	{
		b.x = 0;
		while (b.x < b.img_width)
		{
			if (mandelbrot(b.x, b.y, b.img_height, b.img_width))
				my_put_pixel(&b, b.x, b.y, 0x00FFFFFF);
			else
				my_put_pixel(&b, b.x, b.y, 0x00000000);
			b.x++;
		}
		b.y++;
	} */
	mlx_put_image_to_window(b.mlx, b.win, b.img, 0, 0);
	mlx_key_hook(b.win, my_keypress, &b);
	mlx_hook(b.win, 17, 0L << 0, my_exit, NULL);
	mlx_loop(b.mlx);
}
