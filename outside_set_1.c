/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_set_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:23:54 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/10 17:24:05 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colorizer1(t_env *e, int n)
{
	int		t;
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n * (double)e->max_iter;
	t = (e->maxcolor_t - e->mincolor_t) * ratio + e->mincolor_t;
	r = (e->maxcolor_r - e->mincolor_r) * ratio + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * ratio + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * ratio + e->mincolor_b;
	return (t << 24 | r << 16 | g << 8 | b);
}

int	colorizer2(t_env *e, int n)
{
	int		t;
	int		r;
	int		g;
	int		b;

	r = (e->maxcolor_r - e->mincolor_r) * n / e->max_iter + e->mincolor_r;
	t = (e->maxcolor_t - e->mincolor_t) * n / e->max_iter + e->mincolor_t;
	g = (e->maxcolor_g - e->mincolor_g) * n / e->max_iter + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * n / e->max_iter + e->mincolor_b;
	return (t << 24 | r << 16 | g << 8 | b);
}
