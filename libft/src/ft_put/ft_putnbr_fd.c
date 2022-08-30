/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:47:53 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:38:23 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
n: The integer to output.
fd: The file descriptor on which to write.
return: none
Outputs the integer ’n’ to the given file
descriptor.
*/
static int	charcounter(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	edgecase(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
		write(fd, "0", 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		j;
	char	num[11];

	if (n == -2147483648 || n == 0)
	{
		edgecase(n, fd);
		return ;
	}
	j = charcounter(n);
	i = j - 1;
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		num[i--] = n % 10 + 48;
		n /= 10;
	}
	write(fd, num, j);
}
