/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:17:28 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/07 10:54:04 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errorcheck(int argc, char **argv)
{
	if (argc != 2)
		error_msg("Incorrect number of parameters.");
	if (argv[1][1] ||!ft_strchr("MJS", (int)argv[1][0]))
		error_msg("Incorrect fractal selection.");
}

int	error_msg(char *msg)
{
	int		fd;
	char	*text[500];

	ft_printf("Input error: %s\n", msg);
	fd = open("help.txt", 0);
	read(fd, text, 1000);
	ft_printf("%s\n", text);
	return (my_exit(1));
}

void	errorcheck_windoversion(int argc, char **argv)
{
	int		w;
	int		h;

	if (argc != 4)
		error_msg("Incorrect number of parameters.");
	if (argv[1][1] ||!ft_strchr("MJS", (int)argv[1][0]))
		error_msg("Incorrect fractal selection.");
	if (!ft_isnumberformat(argv[2]) || !ft_isnumberformat(argv[3]))
		error_msg("Incorrect window dimension.");
	w = ft_atoi(argv[2]);
	h = ft_atoi(argv[3]);
	if (w < 500 || w > 2000 || h < 500 || h > 1500)
		error_msg("Incorrect window dimension.");
}

/*
Setting y_max:
range_y = y_max - y_min
range_x = x_max - x_min
range_x / img_width = range_y / img_height
range_y = (range_x / img_width) * img_height
y_max = y_min + (range_x / img_width) * img_height

x axis is taken as fixex axis for window calculation.
x axis 0 is moved to the right for mandelbrot, therefore
x_max should be (around) 0.5 * abs(x_min)
y axis is evenly divided, therefore y min and max are half
of the range of x. but img ratio has to be taken into account
so we have to multiply that with (width/height) to not get
distorted images when using not square image dimensions.
*/
void	set_env(t_env *e, char **argv)
{
	char	fractal;

	fractal = argv[1][0];
	e->img_width = 1400;
	e->img_height = 800;
	//e->color = 0x00FFFFFF;

	if (fractal == 'M')
		e->f = mandelbrot;
	if (fractal == 'S')
		e->f = sierpcircle;
	e->x_min = -2.0;
	e->x_max = e->x_min * -0.4;
	e->x_range = e->x_max - e->x_min;
	e->y_min = -(e->x_range) / 2 * e->img_height / e->img_width;
	e->y_max = (e->x_range) / 2 * e->img_height / e->img_width;
	e->y_range = e->y_max - e->y_min;
	calc_xyranges(e);
	e->max_iter = 200;
	e->min_iter = 20;
	e->iter = 100;
	e->iterstep = 20;
	e->zoomfactor = 0.1;
	e->movefactor = 0.1;
}

void	set_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img_width, e->img_height, "fract'ol");
	e->img = mlx_new_image(e->mlx, e->img_width, e->img_height);
	e->img_addr = mlx_get_data_addr(e->img, &e->img_bpp, &e->img_line_length,
			&e->img_endian);
	e->img_bytespp = e->img_bpp / 8;
}
