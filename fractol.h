/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:54:59 by wmardin           #+#    #+#             */
/*   Updated: 2022/01/29 23:54:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "mlx/mlx.h"
# include "libft/include/libft.h"

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_imgdata;

typedef struct s_mlxdata
{
	void	*mlx;
	void	*win;
}	t_mlxdata;

typedef struct s_circtal
{
	int		x;
	int		y;
	int		iter;
	int		r;
	int		color;
}	t_circtal;

//main.c
int		my_keypress(int key, t_mlxdata *mlx);

//put.c
void	my_put_pixel(t_imgdata *data, int x, int y, int color);
void	my_put_rectangle(t_imgdata *img, int x, int y, int length, int height,
		int color);
void	my_put_circle(t_imgdata *img, int x, int y, int r, int color);

//circtal.c
void	my_circtal(t_imgdata *img, t_circtal circ);

//mod_01.c
int		add_transparency(unsigned char i, int color);

#endif