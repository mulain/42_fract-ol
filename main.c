/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/30 17:10:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_keypress(int key, t_mlxdata *mlx)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(1);
		return (0);
	}
	ft_printf("key:%i\n", key);
	return (0);
}

int	main(void)
{
	t_mlxdata	mlxdata;
	t_imgdata	img;

	mlxdata.mlx = mlx_init();
	mlxdata.win = mlx_new_window(mlxdata.mlx, 1000, 800, "fract-ol");
	img.img = mlx_new_image(mlxdata.mlx, 1920, 1080);
	img.width = 1920;
	img.height = 1080;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	//my_put_pixel(&img, 5, 5, 0x00FF0000);
	//my_put_rectangle(&img, 10, 10, 500, 200, 0x00FF0000);
	my_put_circle(&img, 300, 300, 300, 0x00FFFFFF);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, img.img, 0, 0);
	mlx_key_hook(mlxdata.win, my_keypress, &mlxdata);
	mlx_loop(mlxdata.mlx);
}
