/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:17:28 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/08 13:13:57 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Transparency not used, but infrastructure is kept for potential later
implementation (*_t variables).
*/
void	set_color(t_env *e, char color)
{
	e->mincolor_t = 0;
	e->maxcolor_t = 0;
	if (color == 'r')
	{
		e->color_scheme = 'r';
		e->mincolor_r = 200;
		e->maxcolor_r = 255;
		e->mincolor_g = 50;
		e->maxcolor_g = 255;
		e->mincolor_b = 20;
		e->maxcolor_b = 255;
	}
	else if (color == 'g')
	{
		e->color_scheme = 'g';
		e->mincolor_r = 50;
		e->maxcolor_r = 255;
		e->mincolor_g = 200;
		e->maxcolor_g = 255;
		e->mincolor_b = 20;
		e->maxcolor_b = 255;
	}
	else
		set_color2(e, color);
}

void	set_color2(t_env *e, char color)
{
	if (color == 'b')
	{
		e->color_scheme = 'b';
		e->mincolor_r = 0;
		e->maxcolor_r = 255;
		e->mincolor_g = 100;
		e->maxcolor_g = 255;
		e->mincolor_b = 200;
		e->maxcolor_b = 255;
	}
	if (color == 'd')
	{
		e->color_scheme = 'd';
		e->mincolor_r = 0;
		e->maxcolor_r = 255;
		e->mincolor_g = 0;
		e->maxcolor_g = 255;
		e->mincolor_b = 0;
		e->maxcolor_b = 255;
	}
}
