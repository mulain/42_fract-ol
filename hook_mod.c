/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:48:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 22:47:11 by wmardin          ###   ########.fr       */
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
