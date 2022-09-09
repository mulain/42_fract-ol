/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/09 16:16:13 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	//DEAL WITH MLX LEAKS
	//implement nice colors
	//implement sierpcircle
	//implement gmaps style zoom

	t_env		e;

	check_general(argc, argv);
	set_env(&e, argv);
	set_mlx(&e);
	draw_img(&e);
	mlx_key_hook(e.win, key_release, &e);
	mlx_hook(e.win, 17, 0L << 0, my_exit, NULL);
	mlx_hook(e.win, 5, 1L << 3, mouse_release, &e);
	mlx_mouse_hook(e.win, mouse_press, &e);
	mlx_loop(e.mlx);
}

int	my_exit(int failure)
{
	int		fd;
	char	*text[1000];
	int		readsize;

	if (failure)
	{
		fd = open("help.txt", 0);
		readsize = read(fd, text, 950);
		ft_printf("%i\n", readsize);
		ft_printf("%s\n", text);
		exit(1);
	}
	ft_printf("Exit.\n");
	exit(0);
}
