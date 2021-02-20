#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			j;
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	j = 0;
	i = 0;
	if (!d || !s)
		return (0);
	while (s[j])
		j++;
	if (dstsize == 0)
		return (j);
	while (i < dstsize - 1 && s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (j);
}
