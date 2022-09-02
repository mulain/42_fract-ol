/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circtal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:26:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/02 15:54:08 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	circ.iter = 4;
	circ.r = 600;
	circ.x = img.width / 2;
	circ.y = img.height / 2;
	circ.color = 0x00FFFFFF;
*/
void	my_circtal(t_block *b)
{
	double	factor;
	t_block	b1;

	factor = 1.0;
	if (b->r > 5)
	{
		b1.img_addr = b->img_addr;
		b1.x = b->x - b->r * factor;
		b1.y = b->y;
		b1.r = b->r / (2);
		my_circtal(&b1);
		b1.x = b->x + b->r * factor;
		my_circtal(&b1);
		b1.x = b->x;
		b1.y = b->y + b->r * factor;
		my_circtal(&b1);
	}
	my_put_circle(b, b->x, b->y, b->r);
}
