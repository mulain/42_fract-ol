/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/14 15:07:18 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	//implement sierpcircle
	t_env		e;

	check_general(&e, argc, argv);
	set_env(&e, argv);
	set_mlx(&e);
	e.draw(&e);
	mlx_key_hook(e.win, key_release, &e);
	mlx_hook(e.win, 17, 0L << 0, event_windowdestroy, &e);
	mlx_hook(e.win, 5, 1L << 3, mouse_release, &e);
	mlx_mouse_hook(e.win, mouse_press, &e);
	mlx_loop(e.mlx);
}

/*
This is needed because the hookevent can only receive one parameter.
That is needed for *e, so to also pass int failure we need to call another
function...
*/
int	event_windowdestroy(t_env *e)
{
	my_exit(e, 0);
	return (0);
}

int	my_exit(t_env *e, int failure)
{
	int		fd;
	char	text[1500];
	int		readsize;

	if (failure)
	{
		fd = open("help.txt", 0);
		readsize = read(fd, text, 1500);
		write(1, text, readsize);
		write(1, "\n", 1);
		exit(1);
	}
	else
		mlx_destroy_image(e->mlx, e->img);
	write(1, "Exit.\n", 6);
	exit(0);
}
