/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:20:00 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/08 21:20:00 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strcmp() function compares the two strings s1 and s2.
It returns an integer less than, equal to, or greater than zero
if s1 is found, respectively, to be less than, to match, or be greater than s2.
The strncmp() function is similar, except it only compares the first (at most)
n bytes of s1 and s2.
The strcmp() and strncmp() functions return an integer less than, equal to, or 
greater than zero if s1 (or the first n bytes thereof) is found, respectively, 
to be less than, to match, or be greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	i = 0;
	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (u_s1[i] == 0 && u_s2[i] == 0)
			return (0);
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	return (0);
}
