/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblink <tblink@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:02 by tblink            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:16 by tblink           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		size(int digit)
{
	size_t len;

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

char				*ft_itoa(int num)
{
	char		*buf;
	size_t		len;
	long int	digit;

	len = size(num);
	digit = num;
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
	return (buf);
}
