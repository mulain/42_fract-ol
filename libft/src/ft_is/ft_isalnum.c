/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:19:43 by wmardin           #+#    #+#             */
/*   Updated: 2022/01/29 20:19:43 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The isalnum() and isalnum_l() functions shall test whether c is a
character of class alpha or digit in the current locale, or in
the locale represented by locale, respectively; see the Base
Definitions volume of POSIX.1‐2017, Chapter 7, Locale.
The c argument is an int, the value of which the application
shall ensure is representable as an unsigned char or equal to the
value of the macro EOF. If the argument has any other value, the
behavior is undefined.
The behavior is undefined if the locale argument to isalnum_l()
is the special locale object LC_GLOBAL_LOCALE or is not a valid
locale object handle.
RETURN VALUE
The isalnum() and isalnum_l() functions shall return non-zero if
c is an alphanumeric character; otherwise, they shall return 0.
*/
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (2);
	return (0);
}
