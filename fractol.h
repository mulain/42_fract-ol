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
# include <fcntl.h>
# include <stdio.h>

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
	double	x_min;
	double	x_max;
	double	x_range;
	double	y_min;
	double	y_max;
	double	y_range;
	double	zoomstep;
	double	movestep;
	int		mouse_x;
	int		mouse_y;
	int		mouse_button;
	double	x_mappd;
	double	y_mappd;
	int		r;
	int		color;
	int		max_iter;
	int		maxcolor;
	int		mincolor;
	int		mincolor_t;
	int		mincolor_r;
	int		mincolor_g;
	int		mincolor_b;
	int		maxcolor_t;
	int		maxcolor_r;
	int		maxcolor_g;
	int		maxcolor_b;
	int		(*f)();
}	t_env;

//fractals.c
int		mandelbrot(t_env *e);
int		sierpcircle(t_env *e, int x, int y, int r);
int		sierpcircle_weird(t_env *e, int x, int y, int r);
int		mandelnoob(t_env *e);

//mapping.c
void	map_pxl(t_env *e, int x, int y);
void	draw_img(t_env *e);
int		colorizer(t_env *e, int n);
void	move(t_env *e, int direction);

//put.c
void	put_pixel(t_env *e, int x, int y, int color);
void	put_rectangle(t_env *e, int length, int height);
void	put_circle(t_env *e, int x, int y, int r);
void	put_circle_weird(t_env *e, int a, int b, int r);

//mod_01.c
int		add_transparency(unsigned char i, int color);

//management.c
int		my_exit(int failure);
int		keypress(int key, t_env *e);
int		mouse_action(int button, int mouse_x, int mouse_y, t_env *e);

//setup.c
void	errorcheck(int argc, char **argv);
int		error_msg(char *msg);
void	set_env(t_env *e, char **argv);

#endif