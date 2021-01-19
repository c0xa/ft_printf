/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblink <tblink@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:02 by tblink            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:16 by tblink           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isstring(char *s, t_flags *flags, int i, int lens)
{
	char *res;

	if (!s)
	{
		if (!(s = ft_strdup("(null)")))
			return (0);
		i = 1;
	}
	if (flags->dot >= 0)
		res = (ft_substr(s, 0, flags->dot));
	else
		res = ft_strdup(s);
	lens = ft_strlen(res);
	if (flags->minus != 0)
		lens += (ft_minus_pointer(res, flags->minus, 0, 0));
	else
		ft_putstr_fd(res, 1);
	free(res);
	if (i)
		free(s);
	return (lens);
}
