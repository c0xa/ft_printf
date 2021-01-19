/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblink <tblink@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:02 by tblink            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:16 by tblink           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*buf;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	buf = (char*)malloc((len + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (s1[i])
	{
		buf[i] = s1[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
