/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:14 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/19 14:08:44 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
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
This is needed because the hookevent-function can only receive one parameter.
That parameter is needed for t_env *e, so to also pass int failure this
in-between function is required.
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
	int		discard;

	if (failure)
	{
		fd = open("help.txt", 0);
		readsize = read(fd, text, 1500);
		discard = write(1, text, readsize);
		discard = write(1, "\n", 1);
		exit(1);
	}
	else
		mlx_destroy_image(e->mlx, e->img);
	discard = write(1, "Exit.\n", 6);
	(void)discard;
	exit(0);
}
