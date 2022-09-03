/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/03 08:41:41 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keypress(int key, t_env *e)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		my_exit(0);
	}
	ft_printf("key:%i\n", key);
	return (0);
}

int	my_exit(int failure)
{
	if (failure)
	{
		ft_printf("Exit on error.\n");
		exit(1);
	}
	ft_printf("Exit.\n");
	exit(0);
}

int	error_msg(int argc, char **argv)
{
	ft_printf("Incorrect number of %i argument(s) for %s.\n", argc - 1, argv[0] + 2);
	return (my_exit(1));
}
