/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:17:28 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/03 17:20:11 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errorcheck(int argc, char **argv)
{
	int		w;
	int		h;

	if (argc != 4)
		error_msg();
	if (argv[1][1])
		error_msg();
	if (!ft_strchr("MJS", (int)argv[1][0]))
		error_msg();
	if (!ft_isnumberformat(argv[2]) || !ft_isnumberformat(argv[3]))
		error_msg();
	w = ft_atoi(argv[2]);
	h = ft_atoi(argv[3]);
	if (w < 500 || w > 2000 || h < 500 || h > 1500)
		error_msg();
}

int	error_msg(void)
{
	int		fd;
	char	*text[1000];

	fd = open("help.txt", 0);
	read(fd, text, 1000);
	ft_printf("%s\n", text);
	return (my_exit(1));
}

void	set_env(t_env *e, char **argv)
{
	char	fractal;

	fractal = argv[1][0];
	e->img_width = ft_atoi(argv[2]);
	e->img_height = ft_atoi(argv[3]);
	e->color = 0x00FFFFFF;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img_width, e->img_height, "fract'ol");
	e->img = mlx_new_image(e->mlx, e->img_width, e->img_height);
	e->img_addr = mlx_get_data_addr(e->img, &e->img_bpp, &e->img_line_length,
			&e->img_endian);
	if (fractal == 'M')
		e->f = mandelbrot;
	if (fractal == 'S')
		e->f = sierpcircle;
}
