/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:57:07 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/30 17:19:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_put_rectangle(t_imgdata *img, int x, int y, int length, int height,
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

void	my_put_circle(t_imgdata *img, int a, int b, int r, int color)
{
	int		x;
	int		y;
	int		point;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			point = (x - a) * (x - a) + (y - b) * (y - b) - r * r;
			if (point < 600 && point > -600)
				my_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
