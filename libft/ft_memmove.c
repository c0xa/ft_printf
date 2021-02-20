#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d > s)
		while (i++ < len)
			d[len - i] = s[len - i];
	else
		while (len-- > 0)
			*(d++) = *(s++);
	return (dst);
}
