/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/14 15:08:09 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	sierpcircle(t_env *e, int a, int b, int r)
{
	if (r > e->r_min)
	{
		sierpcircle(e, a - r * e->factor, b, r / 2);
		sierpcircle(e, a + r * e->factor, b, r / 2);
		sierpcircle(e, a, b + r * e->factor, r / 2);
	}
	put_circle(e, a, b, r);
	return (1);
}
