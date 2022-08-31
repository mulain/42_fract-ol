/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:57:07 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/31 11:43:55 by wmardin          ###   ########.fr       */
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
	int		gaussfactor;
	int		i;

	y = 0;
	gaussfactor = 70;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			i = 5;
			point = (x - a) * (x - a) + (y - b) * (y - b) - r * r;
			while (i * gaussfactor < 255 && i > -1)
			{
				if (point < r + r * i && point > -(r + r * i))
				{
					my_put_pixel(img, x, y, add_transparency(i * gaussfactor, color));
					//my_put_pixel(img, x, y, color);
				}
				i--;
			}
			x++;
		}
		y++;
	}
}
