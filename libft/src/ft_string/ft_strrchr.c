/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:09:19 by wmardin           #+#    #+#             */
/*   Updated: 2022/04/08 21:09:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strrchr() function returns a pointer to the last occurrence
of the character c in the string s.
The strchr() and strrchr() functions return a pointer to the
matched character or NULL if the character is not found.  The
terminating null byte is considered part of the string, so that
if c is specified as '\0', these functions return a pointer to
the terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		--i;
	}
	return (NULL);
}
