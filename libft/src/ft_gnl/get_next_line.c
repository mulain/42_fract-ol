/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:46:37 by wmardin           #+#    #+#             */
/*   Updated: 2022/05/31 15:12:29 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Variables:
	-	Statically allocated static char remainder needs 1024 spaces for
		the max amount of possible fd. Since it is static, it will keep its
		contents for the duration of the program, allowing for multiple fd to
		be read in parallel.
	-	Readbuffer is also statically allocated, because it will always have
		the same size: max amount of read bytes + 1.
	-	Line is the workhorse variable.
	-	Readreturn stores the number of bytes read.

Guarding
	-	The expression read(fd, NULL, 0) should only not be 0 if the fd
		is invalid (= -1). So it guards against invalid fd.
	-	BUFFER_SIZE should not be smaller than 1.

Structure
	-	Line must be actively nulled because it can get passed as an
		argument in what would then be its initialization (first line
		in the while readreturn loop).
	-	Check if there is a remainder from prior calls to this fd
		-	If so, the remainder is copied into the line and then
			freed and nulled.
		-	There might be a \n in that remainder so we might have
			to output something.
		-	If there is no \n, we move on to the read part.
	-	First call to read, during which we store the number of bytes
		read in	readreturn.
	-	The while loop has 2 exit conditions:
		-	nothing left to read (or error) -> readreturn no longer > 0
		-	something is found to output and we return stuff
	-	We read before entering the while loop, so we have to update
		line as a first step.
	- 	We check if there is a \n in line after we added the newly
		read stuff.
		If so, we
			-	return the content up to and including the new line
			-	store the content after the new line in remainder[fd]
		If not, we
			- 	read again
			- 	check if we actually did read anything (the while loop
				starts over)
	-	If we did read, the while loop keeps running.
	-	If there was no \n and there was nothing left to read (while loop
		terminates), we still have to output the remaining content of line.
			
*/

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		readbuffer[BUFFER_SIZE + 1];
	char		*line;
	int			readreturn;

	if (read(fd, NULL, 0) || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (remainder[fd])
	{
		line = ft_strdup(remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
		if (ft_findnewline(line) != -1)
			return (ft_makeremainder_returnoutput(line, remainder, fd));
	}
	readreturn = read(fd, readbuffer, BUFFER_SIZE);
	while (readreturn > 0)
	{
		line = ft_appendbuffertoline(line, readbuffer, readreturn);
		if (ft_findnewline(line) != -1)
			return (ft_makeremainder_returnoutput(line, remainder, fd));
		readreturn = read(fd, readbuffer, BUFFER_SIZE);
	}
	return (line);
}
