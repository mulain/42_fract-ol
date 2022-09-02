/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:57:07 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/02 15:34:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(t_block *b, int x, int y, int color)
{
	char	*pxl;

	pxl = b->img_addr + (y * b->img_line_length + x * (b->img_bpp / 8));
	*(unsigned int *)pxl = color;
}

void	my_put_rectangle(t_block *b, int length, int height)
{
	int		l;
	int		h;
	int		x;
	int		y;

	x = 100;
	y = 100;
	h = 0;
	while (h < height)
	{
		l = 0;
		while (l < length)
		{
			my_put_pixel(b, x + l, y + h, b->color);
			l++;
		}
		h++;
	}
}

void	my_put_circle(t_block *bl, int a, int b, int r)
{
	int		x;
	int		y;
	int		point;
	int		gaussfactor;
	int		i;

	y = 0;
	gaussfactor = 70;
	while (y < bl->img_height)
	{
		x = 0;
		while (x < bl->img_width)
		{
			i = 5;
			point = (x - a) * (x - a) + (y - b) * (y - b) - r * r;
			while (i * gaussfactor < 255 && i > -1)
			{
				if (point < r + r * i && point > -(r + r * i))
				{
					my_put_pixel(bl, x, y, add_transparency(i * gaussfactor, bl->color));
					//my_put_pixel(img, x, y, color);
				}
				i--;
			}
			x++;
		}
		y++;
	}
}
