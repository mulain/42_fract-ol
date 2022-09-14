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
	//mlx
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_bytespp;
	int		img_line_length;
	int		img_endian;
	int		img_width;
	int		img_height;
	//coordinates
	double	x_min;
	double	x_max;
	double	x_range;
	double	y_min;
	double	y_max;
	double	y_range;
	double	x_mappd;
	double	y_mappd;
	//navigation
	double	zoomfactor;
	double	movefactor;
	//mouse actions
	int		mouse_press_x;
	int		mouse_press_y;
	int		mouse_release_x;
	int		mouse_release_y;
	int		mouse_button;
	//iteration settings
	int		max_iter;
	int		min_iter;
	int		iter;
	int		iterstep;
	//julia settings
	double	julia_x;
	double	julia_y;
	//sierpcircle settings
	double	r_start;
	double	r_min;
	double	a_mappd;
	double	b_mappd;
	double	r_mappd;
	double	factor;
	double	line;
	int		in_sierp;
	//color settings
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
	char	color_scheme;
	//functions
	void	(*draw)();
	int		(*fractal)();
	int		(*outside_set)();
	int		(*inside_set)();
}	t_env;

//main.c
int		main(int argc, char **argv);
int		my_exit(t_env *e, int failure);
int		event_windowdestroy(t_env *e);

//fractals_1.c
int		mandelbrot(t_env *e);
int		julia(t_env *e);
int		burningship(t_env *e);
int		mandelnoob(t_env *e);

//fractals_2.c
int		sierpcircle_slow(t_env *e);
void	sierphelper_slow(t_env *e, double r, double x, double y);

//fractals_save.c
int		sierpcircle(t_env *e, int a, int b, int r);
void	put_circle(t_env *e, int a, int b, int r);
double	getdelta(t_env *e);

//draw.c
void	draw_pxl(t_env *e);
void	draw_sierp(t_env *e);
void	put_pixel(t_env *e, int x, int y, int color);

//inside_set_1.c
int		black(int x, int y);
int		white(int x, int y);
int		pixelizer(int x, int y);

//inside_set_2.c
int		pixelizer42(int x, int y);
int		pixelizer42_rot_0(int x, int y, int color, int bckgr);
int		pixelizer42_rot_neg90(int x, int y, int color, int bckgr);
int		pixelizer42_rot_180(int x, int y, int color, int bckgr);
int		pixelizer42_flip_hor(int x, int y, int color, int bckgr);

//outside_set_1.c
int		colorizer1(t_env *e, int n);
int		colorizer2(t_env *e, int n);
int		colorizer3(t_env *e, int n);
int		colorizer4(t_env *e, int n);
int		colorizer5(t_env *e, int n);

//calculation.c
void	map_pxl(t_env *e, int x, int y);
void	calc_xyranges(t_env *e);
double	calc_absolute_double(double n);
int		calc_absolute_int(int n);

//put.c
void	put_pixel_guarded(t_env *e, int x, int y, int color);
void	put_rectangle(t_env *e, int length, int height);
void	put_circle_weird(t_env *e, int a, int b, int r);

//hooks.c
int		key_release(int key, t_env *e);
int		mouse_press(int button, int mouse_x, int mouse_y, t_env *e);
int		mouse_release(int button, int mouse_x, int mouse_y, t_env *e);

//hook_nav.c
void	move_key(t_env *e, int direction);
void	move_mouse(t_env *e);
void	zoom(t_env *e, int zoom_in);

//hook_mod.c
void	mod_inside_set(t_env *e);
void	mod_outside_set(t_env *e);
void	mod_iter(t_env *e, int key);
void	mod_color(t_env *e);
void	mod_colorizer(t_env *e);

//inputparsing.c
void	check_general(t_env *e, int argc, char **argv);
void	check_julia(t_env *e, int argc, char **argv);

//setup_1.c
void	set_env(t_env *e, char **argv);
void	set_mlx(t_env *e);
void	set_vars_generic(t_env *e);
void	set_vars_brot(t_env *e);
void	set_vars_sierpcircle(t_env *e);

//setup_2.c
void	set_mandelbrot(t_env *e);
void	set_julia(t_env *e, char set);
void	set_julia2(t_env *e, char set);
void	set_burningship(t_env *e);
void	set_mandelnoob(t_env *e);

//setup_3.c
void	set_sierpcircle(t_env *e);

//setup_4.c
void	set_color(t_env *e, char color);
void	set_color2(t_env *e, char color);

#endif