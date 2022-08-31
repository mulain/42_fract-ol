/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circtal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:26:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/31 08:42:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_circtal(t_imgdata *img, t_circtal circ)
{
	t_circtal	circnext;
	int			num;
	int			denom;

	/* ft_printf("iter:%i\n", circ.iter);
	ft_printf("x:%i\n", circ.x);
	ft_printf("y:%i\n", circ.y);
	ft_printf("r:%i\n", circ.r);
 	*/
 	num = 2;
	denom = 3;
	circnext.color = circ.color;
	if (circ.iter)
	{
		circnext.x = circ.x - circ.r * num / denom;
		circnext.y = circ.y;
		circnext.r = circ.r / (2);
		circnext.iter = circ.iter - 1;
		my_circtal(img, circnext);
		circnext.x = circ.x + circ.r * num / denom;
		//circnext.y = circ.y;
		//circnext.r = circ.r / 2;
		//circnext.iter = circ.iter - 1;
		my_circtal(img, circnext);
		circnext.x = circ.x;
		circnext.y = circ.y + circ.r * num / denom;
		my_circtal(img, circnext);
		circnext.y = circ.y - circ.r * num / denom;
		my_circtal(img, circnext);
	}
	my_put_circle(img, circ.x, circ.y, circ.r, circ.color);
}
