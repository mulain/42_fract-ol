/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circtal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:26:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/02 17:12:20 by wmardin          ###   ########.fr       */
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
void	my_circtal(t_block *b, int x, int y, int r)
{
	int		factor;

	factor = 1;
	if (r > 5)
	{
		my_circtal(b, x - r * factor, y, r / 2);
		my_circtal(b, x + r * factor, y, r / 2);
		my_circtal(b, x, y + r * factor, r / 2);
	}
	my_put_circle(b, x, y, r);
}
