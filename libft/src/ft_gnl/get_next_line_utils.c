/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:24:53 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/22 08:24:53 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
- Appends the readbuffer to line
- First, a 0 byte is added at index = amount of read bytes; now we have a string
- If line is NULL, returns only the content of the readbuffer.
- If line is not NULL, mallocs for line and readbuffer
- Copies line and readbuffer into the malloc'd address and 0 terminates
- Frees line and returns the malloc'd address as the new line
*/

char	*ft_appendbuffertoline(char *line, char *readbuffer, int readreturn)
{
	int		i;
	int		len_readbuffer;
	int		len_line;
	char	*output;

	i = 0;
	readbuffer[readreturn] = 0;
	len_readbuffer = ft_strlen_gnl(readbuffer);
	if (!line)
		return (ft_strdup(readbuffer));
	len_line = ft_strlen_gnl(line);
	output = malloc((len_line + len_readbuffer + 1) * sizeof(char));
	while (line[i])
	{
		output[i] = line[i];
		i++;
	}
	while (readbuffer[i - len_line])
	{
		output[i] = readbuffer[i - len_line];
		i++;
	}
	output[i] = 0;
	free(line);
	return (output);
}

/*
- Searches for \n
- If found, returns index of \n
- If not found, returns -1 (index could be 0)
*/

int	ft_findnewline(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*
- Measures length of line and position of \n
- If \n is at the last position of line, then remainder
	should be empty:
	- Nulls remainder and frees
	- returns line
- If there remains content after \n, this is saved in remainder
	- strdup beginning with the position after the first \n
		in line.
- 0 terminates line after the first \n
- this means line is bigger than the contained string but I didn't want to 
	make a new malloc and free the old line.
*/

char	*ft_makeremainder_returnoutput(char *line, char **remainder, int fd)
{
	int		ind_newline;
	int		len_line;

	ind_newline = ft_findnewline(line);
	len_line = ft_strlen_gnl(line);
	if (ind_newline == len_line - 1)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (line);
	}
	remainder[fd] = ft_strdup(line + ind_newline + 1);
	line[ind_newline + 1] = 0;
	return (line);
}

char	*ft_strdup(const char *source)
{
	int		i;
	char	*output;

	i = 0;
	output = malloc((ft_strlen_gnl(source) + 1) * sizeof(char));
	while (source[i])
	{
		output[i] = source[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
