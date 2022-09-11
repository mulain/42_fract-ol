/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:05:22 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/11 17:47:57 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_img(t_env *e)
{
	int		x;
	int		y;

	calc_xyranges(e);
	y = 0;
	while (y < e->img_height)
	{
		x = 0;
		while (x < e->img_width)
		{
			map_pxl(e, x, y);
			put_pixel(e, x, y, e->fractal(e));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	put_pixel(t_env *e, int x, int y, int color)
{
	char	*pxl;

	pxl = e->img_addr + (y * e->img_line_length + x * (e->img_bytespp));
	*(unsigned int *)pxl = color;
}

/* void	paraminfo(t_env *e)
{
	ft_printf("Base color: %s\n", e->color);
	ft_printf("Inside set: %s\n", e->inside);
	ft_printf("Outside set: %s\n", e->outside);
	ft_printf("Max iterations: %i\n", e->max_iter);
} */