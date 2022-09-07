/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelizer42.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:04:32 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 19:24:46 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pixelizer42(int x, int y)
{
	int		x_mod;
	int		y_mod;
	int		color;
	int		bckgr;

	color = 0x00FFFFFF;
	bckgr = 0x00000000;
	x_mod = x % 9;
	y_mod = y % 9;
	if (y_mod == 0 || x_mod == 0 || y_mod == 1 || x_mod == 1
		|| y_mod == -1 || x_mod == -1)
		return (bckgr);
	if (x_mod > 0 && y_mod > 0)
		return (pixelizer42_rot_180(x_mod, y_mod, color, bckgr));
	if (x_mod < 0 && y_mod > 0)
		return (pixelizer42_flip_hor(-x_mod, y_mod, color, bckgr));
	if (x_mod > 0 && y_mod < 0)
		return (pixelizer42_flip_hor(x_mod, -y_mod, color, bckgr));
	if (x_mod < 0 && y_mod < 0)
		return (pixelizer42_rot_0(-x_mod, -y_mod, color, bckgr));
	return (bckgr);
}

int	pixelizer42_rot_0(int x, int y, int color, int bckgr)
{
	if (x == 2 && (y == 2 || y == 3 || y == 4 || y == 5))
		return (color);
	if (x == 3 && y == 5)
		return (color);
	if (x == 4)
		return (color);
	if (x == 6 && (y != 3 && y != 4))
		return (color);
	if (x == 7 && (y == 2 || y == 5 || y == 8))
		return (color);
	if (x == 8 && (y != 6 && y != 7))
		return (color);
	return (bckgr);
}

int	pixelizer42_rot_neg90(int x, int y, int color, int bckgr)
{
	if (x == 2 && (y == 2 || y == 3 || y == 4 || y == 6 || y == 8))
		return (color);
	if (x == 3 && (y == 2 || y == 6 || y == 8))
		return (color);
	if (x == 4 && (y == 2 || y == 6 || y == 8))
		return (color);
	if (x == 5 && y != 5)
		return (color);
	if (x == 6 && (y == 4 || y == 6))
		return (color);
	if (x == 7 && (y == 4 || y == 6))
		return (color);
	if (x == 8 && (y != 5 && y != 7 && y != 8))
		return (color);
	return (bckgr);
}

int	pixelizer42_rot_180(int x, int y, int color, int bckgr)
{
	if (x == 2 && (y != 3 && y != 4))
		return (color);
	if (x == 3 && (y == 2 || y == 5 || y == 8))
		return (color);
	if (x == 4 && (y != 6 && y != 7))
		return (color);
	if (x == 6)
		return (color);
	if (x == 7 && y == 5)
		return (color);
	if (x == 8 && (y != 2 && y != 3 && y != 4))
		return (color);
	return (bckgr);
}

int	pixelizer42_flip_hor(int x, int y, int color, int bckgr)
{
	if (x == 2 && (y != 2 && y != 3 && y != 4))
		return (color);
	if (x == 3 && y == 5)
		return (color);
	if (x == 4)
		return (color);
	if (x == 6 && (y != 6 && y != 7))
		return (color);
	if (x == 7 && (y == 2 || y == 5 || y == 8))
		return (color);
	if (x == 8 && (y != 3 && y != 4))
		return (color);
	return (bckgr);
}
