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

typedef struct s_block
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_line_length;
	int		img_endian;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		r;
	int		iter;
	int		color;
}	t_block;



//fractals.c
int		mandelbrot(int x, int y, int height, int width);

//put.c
void	my_put_pixel(t_block *data, int x, int y, int color);
void	my_put_rectangle(t_block *b, int length, int height);
void	my_put_circle(t_block *b, int x, int y, int r);

//circtal.c
void	my_circtal(t_block *b);

//mod_01.c
int		add_transparency(unsigned char i, int color);

//management.c
int		my_exit(void);
int		my_keypress(int key, t_block *b);

#endif