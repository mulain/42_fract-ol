/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_set_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:23:54 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/19 16:56:18 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Solid colors.
*/
int	colorizer1(t_env *e, int n)
{
	int		t;
	int		r;
	int		g;
	int		b;

	t = (e->maxcolor_t - e->mincolor_t) * n / e->max_iter + e->mincolor_t;
	r = (e->maxcolor_r - e->mincolor_r) * n / e->max_iter + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * n / e->max_iter + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * n / e->max_iter + e->mincolor_b;
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
Solid colors, but random overflow effects because n is multiplied with max_iter.
There is overflow into t because of this.
To prevent this, a mask is used for return. If the mask is removed, there
is an overlay / dopplerian effect when zooming in - but I didn't want it.
*/
int	colorizer2(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n * e->max_iter;
	r = (e->maxcolor_r - e->mincolor_r) * ratio + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * ratio + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * ratio + e->mincolor_b;
	return (0x00FFFFFF & (0x00 << 24 | r << 16 | g << 8 | b));
}

/*
Bernstein color formula.
*/
int	colorizer3(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n / e->max_iter;
	r = 9 * (1 - ratio) * ratio * ratio * ratio * 255;
	g = 15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255;
	b = 8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255;
	return (0x00 << 24 | r << 16 | g << 8 | b);
}

/*
Bernstein, but r and b switched.
*/
int	colorizer4(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n / e->max_iter;
	b = 9 * (1 - ratio) * ratio * ratio * ratio * 255;
	g = 15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255;
	r = 8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255;
	return (0x00 << 24 | r << 16 | g << 8 | b);
}
