/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/03 12:58:30 by wmardin          ###   ########.fr       */
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

int	error_msg(void)
{
	int		fd;
	char	*text[1000];

	fd = open("help.txt", 0);
	read(fd, text, 1000);
	ft_printf("%s\n", text);
	return (my_exit(1));
}
