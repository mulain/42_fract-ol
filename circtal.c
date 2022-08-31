/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circtal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:26:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/31 11:04:40 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_circtal(t_imgdata *img, t_circtal circ)
{
	t_circtal	circnext;
	int			num;
	int			denom;

 	num = 1;
	denom = 1;
	circnext.color = circ.color;
	if (circ.r > 5)
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
		//circnext.y = circ.y - circ.r * num / denom;
		//my_circtal(img, circnext);
	}
	my_put_circle(img, circ.x, circ.y, circ.r, circ.color);
}
