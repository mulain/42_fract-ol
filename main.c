/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/29 12:03:13 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_put_line(unsigned int *start, int length, int color)
{
	int				i;
	unsigned int	*pxl;

	i = 1;
	pxl = start;
	while (i <= length)
	{
		*pxl = color;
		pxl = pxl + 1;
		color += 1000;
		i++;
	}
}

void	my_put_rectangle(t_data *img, int x, int y, int length, int height,
		int color)
{
	int		l;
	int		h;

	h = 0;
	while (h < height)
	{
		l = 0;
		while (l < length)
		{
			my_put_pixel(img, x + l, y + h, color);
			l++;
		}
		h++;
	}
}

int	my_keystroke(int key, void *param)
{
	write(1, &key, 1);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2560, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 2560, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_put_pixel(&img, 5, 5, 0x00FF0000);
	my_put_rectangle(&img, 10, 10, 500, 200, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, my_keystroke, NULL);
	mlx_loop(mlx);
}
