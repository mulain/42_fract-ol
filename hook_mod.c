/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:48:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/12 18:44:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mod_inside_set(t_env *e)
{
	if (e->inside_set == black)
	{
		ft_printf("Pixels in set colored: white.\n");
		e->inside_set = white;
	}
	else if (e->inside_set == white)
	{
		ft_printf("Pixels in set colored: technocloud.\n");
		e->inside_set = pixelizer;
	}
	else if (e->inside_set == pixelizer)
	{
		ft_printf("Pixels in set colored: 42.\n");
		e->inside_set = pixelizer42;
	}
	else if (e->inside_set == pixelizer42)
	{
		ft_printf("Pixels in set colored: black.\n");
		e->inside_set = black;
	}
	draw_img(e);
}

void	mod_outside_set(t_env *e)
{
	if (e->outside_set == colorizer1)
	{
		e->outside_set = colorizer2;
		ft_printf("Pixels outside set colored: wacky.\n");
	}
	else if (e->outside_set == colorizer2)
	{
		e->outside_set = colorizer3;
		ft_printf("Pixels outside set colored: bernstein.\n");
	}
	else if (e->outside_set == colorizer3)
	{
		e->outside_set = colorizer4;
		ft_printf("Pixels outside set colored: reverse bernstein.\n");
	}
	else if (e->outside_set == colorizer4)
	{
		e->outside_set = colorizer1;
		ft_printf("Pixels outside set colored: solid.\n");
	}
	draw_img(e);
}

void	mod_iter(t_env *e, int key)
{
	if (key == KEY_W)
	{
		if (e->iter < e->max_iter)
			e->iter += e->iterstep;
	}
	else
	{
		if (e->iter > e->min_iter)
			e->iter -= e->iterstep;
	}
	ft_printf("max iterations: %i\n", e->iter);
	draw_img(e);
}

void	mod_color(t_env *e)
{
	if (e->color_scheme == 'r')
	{
		set_color(e, 'g');
		ft_printf("Base color: green\n");
	}
	else if (e->color_scheme == 'g')
	{
		set_color(e, 'b');
		ft_printf("Base color: blue\n");
	}
	else if (e->color_scheme == 'b')
	{
		set_color(e, 'd');
		ft_printf("Base color: dark (black)\n");
	}
	else if (e->color_scheme == 'd')
	{
		set_color(e, 'r');
		ft_printf("Base color: red\n");
	}
	//param_info(e);
	draw_img(e);
}

void	mod_colorizer(t_env *e)
{
	if (e->color_scheme == 'r')
		set_color(e, 'g');
	else if (e->color_scheme == 'g')
		set_color(e, 'b');
	else if (e->color_scheme == 'b')
		set_color(e, 'd');
	else if (e->color_scheme == 'd')
		set_color(e, 'r');
	draw_img(e);
}
