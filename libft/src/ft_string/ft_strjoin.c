/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:35:36 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:43:52 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s1: The prefix string.
s2: The suffix string.
return: The new string. NULL if the allocation fails.
Allocates (with malloc(3)) and returns a new string, which is the result of
the concatenation of ’s1’ and ’s2’.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	out = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, len_s1 + 1);
	ft_strlcpy(out + len_s1, s2, len_s2 + 1);
	return (out);
}

/* int	main(void)
{
	char	*s1;
	char	*s2;
	char	*out;

	s1 = "knudel";
	s2 = "hair";
	out = ft_strjoin(s1, s2);
	printf("%s\n", out);	
} */