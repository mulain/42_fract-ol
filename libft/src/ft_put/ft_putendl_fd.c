/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:37:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: The string to output.
fd: The file descriptor on which to write.
return: none
Outputs the string ’s’ to the given file descriptor
followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = ft_strlen(s);
		write(fd, s, i);
		write(fd, "\n", 1);
	}
}
