/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:52:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/14 20:58:56 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_general(t_env *e, int argc, char **argv)
{
	if (argc < 2 || argc > 4)
		my_exit(e, 1);
	if (argv[1][1] || !ft_strchr("MJBNS", (int)argv[1][0]))
		my_exit(e, 1);
	if (argv[1][0] == 'S')
		return ;
	if (argv[2][1] || !ft_strchr("rgbd", (int)argv[2][0]))
		my_exit(e, 1);
	if (argv[1][0] == 'J')
		check_julia(e, argc, argv);
	else if (argc != 3)
		my_exit(e, 1);
}

void	check_julia(t_env *e, int argc, char **argv)
{
	if (argc != 4)
		my_exit(e, 1);
	if (argv[3][1] || !ft_strchr("12345678", (int)argv[3][0]))
		my_exit(e, 1);
}
