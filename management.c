/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/02 15:36:33 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_keypress(int key, t_block *b)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(b->mlx, b->win);
		my_exit();
	}
	ft_printf("key:%i\n", key);
	return (0);
}

int	my_exit(void)
{
	ft_printf("later!\n");
	exit (1);
}
