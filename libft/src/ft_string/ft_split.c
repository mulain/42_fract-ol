/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:51:23 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/28 10:41:11 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: The string to be split.
c: The delimiter character.

return: The array of new strings resulting from the split.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

/*
Counts strings by identifying delimiters not followed by delimiters or 0.
Does not identify the first string, because either
- there is no delimiter in front of it
- if there is a delimiter before the first string, the index i will already
have passed by it in the first while loop.
Therefore j has to returned as j + 1.
If j is returned as 0, an edge case of all delimiters
or empty string is present.
Malloc for the final array uses j + 1 + 1, because another space for
the NULL pointer is needed.
*/
static int	count_strings(char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (j);
	while (s[i] == c)
		i++;
	if (i == len)
		return (j);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			j++;
		i++;
	}
	return (j + 1);
}

static int	count_chars(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		i++;
	}
	return (j);
}

static void	transfercleanstring(char *copy, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			copy[j] = s[i];
			j++;
		}
		if (s[i] == c && s[i + 1] != c)
		{
			copy[j] = 0;
			j++;
		}
		i++;
	}
	return ;
}

static char	**makearray(const char *s, char c, char *copy, int j)
{
	char	**out;
	int		i;

	out = malloc((j + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	out[j] = NULL;
	i = j + count_chars(s, c) - 2;
	while (i > -1)
	{
		if (copy[i] == 0)
		{
			out[j - 1] = ft_strdup(copy + i + 1);
			if (!out[j - 1])
				return (NULL);
			j--;
		}
		i--;
	}
	out[0] = ft_strdup(copy);
	if (!out[0])
		return (NULL);
	free(copy);
	return (out);
}

/*
Concept:
- Count number of strings
- deal with edge cases: empty string / only delimiters
- Count number of chars
- number of strings + number of chars = total needed mem for new string
because mem = number of chars + number of 0 bytes (= number of chars)
- allocate needed mem to copy
- transfer clean string to copy by
	- omitting starting delimiters
	- copying non delimiters
	- inserting 0 bytes for delimiters that are not followed by delimiters
		and skipping delimiters which are followed by other delimiters
	- final 0 byte does not have to be written because calloc was used -
		but it will be written if array ends with delimiter (but 0
		will already have been at that position)
*/
char	**ft_split(char const *s, char c)
{
	int		j;
	char	*copy;
	char	**out;

	if (!s)
		return (NULL);
	j = count_strings(s, c);
	if (j == 0)
	{
		out = ft_calloc(1, sizeof(char *));
		if (!out)
			return (NULL);
		return (out);
	}
	copy = ft_calloc(j + count_chars(s, c), sizeof(char));
	if (!copy)
		return (NULL);
	transfercleanstring(copy, s, c);
	return (makearray(s, c, copy, j));
}
