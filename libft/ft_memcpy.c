#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = dst;
	s = (unsigned char*)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}
