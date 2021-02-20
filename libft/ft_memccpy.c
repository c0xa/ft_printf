#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n > i)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return ((void*)d + i + 1);
		i++;
	}
	return (NULL);
}
