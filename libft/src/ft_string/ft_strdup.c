/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:39:23 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:43:03 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strdup() function returns a pointer to a new string which is
a duplicate of the string s. Memory for the new string is
obtained with malloc(3), and can be freed with free(3).
It returns NULL if insufficient memory was
available, with errno set to indicate the error.
Use "sizeof(char)" in case of non char variables
*/
char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;

	i = ft_strlen(s) + 1;
	c = malloc(i);
	if (!c)
		return (NULL);
	ft_strlcpy(c, s, i);
	return (c);
}
