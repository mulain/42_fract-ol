/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:52:46 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/08 10:00:33 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_general(int argc, char **argv)
{
	if (argc < 3 || argc > 4)
		my_exit(1);
	if (argv[1][1] || !ft_strchr("MJBSN", (int)argv[1][0]))
		my_exit(1);
	if (argv[2][1] || !ft_strchr("wrgb", (int)argv[2][0]))
		my_exit(1);
	if (argv[1][0] == 'J')
		check_julia(argc, argv);
	else if (argc != 3)
		my_exit(1);
}

void	check_julia(int argc, char **argv)
{
	if (argc != 4)
		my_exit(1);
	if (argv[3][1] || !ft_strchr("123456", (int)argv[3][0]))
		my_exit(1);
}