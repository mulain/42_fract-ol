/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:02:19 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/04 10:13:15 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_env *e, int x, int y, int color)
{
	char	*pxl;

	pxl = e->img_addr + (y * e->img_line_length + x * (e->img_bpp / 8));
	*(unsigned int *)pxl = color;
}

int	colorizer(t_env *e, int n)
{
	int		t;
	int		r;
	int		g;
	int		b;

	e->mincolor_t = 0;
	e->maxcolor_t = 0;
	e->mincolor_r = 0;
	e->maxcolor_r = 255;
	e->mincolor_g = 0;
	e->maxcolor_g = 255;
	e->mincolor_b = 0;
	e->maxcolor_b = 255;
	t = (e->maxcolor_t - e->mincolor_t) * n / e->max_iter + e->mincolor_t;
	r = (e->maxcolor_r - e->mincolor_r) * n / e->max_iter + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * n / e->max_iter + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * n / e->max_iter + e->mincolor_b;
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_test(t_env *e)
{
	e->img_width = 900;
	e->img_height = 900;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img_width, e->img_height, "fract'ol");
	e->img = mlx_new_image(e->mlx, e->img_width, e->img_height);
	e->img_addr = mlx_get_data_addr(e->img, &e->img_bpp, &e->img_line_length,
			&e->img_endian);
	e->max_iter = 50;
}

int	main(void)
{
	t_env	e;
	int		n;
	int		color;

	set_test(&e);
	n = 1;
	while (n <= e.max_iter)
	{
		color = colorizer(&e, n);
		printf("0x%X\n", color);
		put_pixel(&e, n, n, color);
		n++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
}
