/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:08:04 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 13:10:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Before calling this, ranges must be correct.
Run calc_xyranges before calling to update them.
*/
void	map_pxl(t_env *e, int x, int y)
{
	e->x_mappd = e->x_min + x * e->x_range / e->img_width;
	e->y_mappd = e->y_min + y * e->y_range / e->img_height;
}

void	calc_xyranges(t_env *e)
{
	e->x_range = e->x_max - e->x_min;
	e->y_range = e->y_max - e->y_min;
}

double	calc_absolute(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
