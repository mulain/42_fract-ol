/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:16:42 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/31 11:29:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	add_transparency(unsigned char i, int color)
{
	int		newcolor;

	newcolor = i << 24 | color;
	return (newcolor);
}