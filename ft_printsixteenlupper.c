/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsixteenlupper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblink <tblink@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:02 by tblink            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:16 by tblink           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoasixteenlupper(unsigned long long digit)
{
	unsigned long long	num;
	char				*buf;
	size_t				len;

	len = sizesixteen(digit, 16);
	if (!(buf = (char*)malloc(len + 1 * (sizeof(char)))))
		return (NULL);
	*(buf + len) = '\0';
	while (len--)
	{
		num = digit % 16;
		if (num > 9)
			*(buf + len) = num + 55;
		else
			*(buf + len) = num + 48;
		digit /= 16;
	}
	return (buf);
}

static char		*ft_dotnil(unsigned long long int n, char *res)
{
	if (n == 0)
	{
		free(res);
		res = ft_strdup("");
	}
	return (res);
}

int				ft_ishexadecimalupper(unsigned long long un, int i,
				size_t lens, t_flags *flags)
{
	char *res;

	if (!(res = ft_itoasixteenlupper(un)))
		return (0);
	if (flags->dot >= (int)ft_strlen(res) && flags->dot > 0)
		res = ft_dotzero(flags->dot, res, ft_strlen(res));
	else if (flags->dot == 0)
		res = ft_dotnil(un, res);
	if (flags->dot >= 0 && flags->zero > 0)
		flags->minus = flags->zero * -1;
	i = flags->minus * (flags->minus < 0 ? -1 : 1);
	if (flags->minus != 0 && i > (int)ft_strlen(res))
	{
		lens += (ft_minus_pointer(res, flags->minus, 0, 0));
		i = -1;
	}
	else if (flags->zero > (int)lens && flags->zero > 0)
		res = ft_dotzero(flags->zero, res, ft_strlen(res) + 0);
	if (i != -1)
		ft_putstr_fd(res, 1);
	lens += ft_strlen(res);
	free(res);
	return ((int)lens - 1);
}
