/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblink <tblink@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:02 by tblink            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:16 by tblink           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	size(unsigned int digit)
{
	size_t		len;

	len = 0;
	if (digit == 0)
		return (1);
	while (digit)
	{
		digit /= 10;
		len++;
	}
	return (len);
}

static char		*ft_itoaforun(unsigned int num)
{
	char		*buf;
	size_t		len;
	long int	digit;

	len = size(num);
	digit = num;
	len += (digit < 0 ? 1 : 0);
	if (digit < 0)
	{
		digit *= -1;
	}
	if (!(buf = (char*)malloc(len + 1 * (sizeof(char)))))
		return (NULL);
	*(buf + len) = '\0';
	while (len--)
	{
		*(buf + len) = digit % 10 + 48;
		digit /= 10;
	}
	if (buf[0] == '0' && num != 0)
		buf[0] = '-';
	return (buf);
}

static char		*ft_dotnil(unsigned int n, char *res)
{
	if (n == 0)
	{
		free(res);
		res = ft_strdup("");
	}
	return (res);
}

int				ft_isunsignedint(unsigned int un, int i,
				size_t lens, t_flags *flags)
{
	char	*res;

	if (!(res = ft_itoaforun(un)))
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
