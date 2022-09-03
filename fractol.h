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

typedef struct s_env
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
}	t_env;



//fractals.c
int		mandelbrot(int x, int y, int height, int width);
void	sierpcircle(t_env *e, int x, int y, int r);
void	sierpcircle_weird(t_env *e, int x, int y, int r);

//put.c
void	put_pixel(t_env *data, int x, int y, int color);
void	put_rectangle(t_env *e, int length, int height);
void	put_circle(t_env *e, int x, int y, int r);
void	put_circle_weird(t_env *e, int a, int b, int r);

//mod_01.c
int		add_transparency(unsigned char i, int color);

//management.c
int		my_exit(int failure);
int		error_msg(int argc, char **argv);
int		keypress(int key, t_env *e);

#endif