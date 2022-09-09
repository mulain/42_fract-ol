/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:30:49 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/09 21:10:05 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandelbrot(t_env *e)
{
	e->fractal = mandelbrot;
	set_vars_brot(e);
}

void	set_burningship(t_env *e)
{
	e->fractal = burningship;
	set_vars_generic(e);
}

void	set_mandelnoob(t_env *e)
{
	e->fractal = mandelnoob;
	set_vars_brot(e);
}

void	set_julia(t_env *e, char set)
{
	e->fractal = julia;
	set_vars_generic(e);
	if (set == '1')
	{
		e->julia_x = -0.79;
		e->julia_y = 0.15;
	}
	else if (set == '2')
	{
		e->julia_x = -0.162;
		e->julia_y = 1.04;
	}
	else if (set == '3')
	{
		e->julia_x = 0.3;
		e->julia_y = -0.01;
	}
	else if (set == '4')
	{
		e->julia_x = -1.476;
		e->julia_y = 0;
	}
	else
		set_julia2(e, set);
}

void	set_julia2(t_env *e, char set)
{

	if (set == '5')
	{
		e->julia_x = -0.12;
		e->julia_y = 0.77;
	}
	if (set == '6')
	{
		e->julia_x = 0.28;
		e->julia_y = 0.008;
	}
	if (set == '7')
	{
		e->julia_x = -0.4;
		e->julia_y = -0.59;
	}
	if (set == '8')
	{
		e->julia_x = -1.05;
		e->julia_y = 0.27;
	}
}
