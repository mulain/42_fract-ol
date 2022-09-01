/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/01 22:20:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_keypress(int key, t_mlxdata *mlx)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (0);
	}
	ft_printf("key:%i\n", key);
	return (0);
}

int	my_exit(void)
{
	ft_printf("later!\n");
	exit (1);
}

int	main(void)
{
	t_mlxdata	mlxdata;
	t_imgdata	img;
	t_circtal	circ;
	int			x;
	int			y;

	y = 0;
	img.width = 1000;
	img.height = 1000;
	mlxdata.mlx = mlx_init();
	mlxdata.win = mlx_new_window(mlxdata.mlx, img.width, img.height, "fract-ol");
	img.img = mlx_new_image(mlxdata.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	circ.iter = 4;
	circ.r = 600;
	circ.x = img.width / 2;
	circ.y = img.height / 2;
	circ.color = 0x00FFFFFF;
	//my_put_pixel(&img, 0, 0, 0x00FF0000);
	//my_put_rectangle(&img, 10, 10, 500, 200, 0x00FF0000);
	//my_put_circle(&img, 500, 500, 200, 0x00FFFFFF);
	//my_circtal(&img, circ);
	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			//my_put_pixel(&img, x, y, 250);
			if (mandelbrot(x, y, img.height, img.width))
				my_put_pixel(&img, x, y, 0x00FFFFFF);
			else
				my_put_pixel(&img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, img.img, 0, 0);
	mlx_key_hook(mlxdata.win, my_keypress, &mlxdata);
	mlx_hook(mlxdata.win, 17, 0L << 0, my_exit, NULL);
	mlx_loop(mlxdata.mlx);
}
