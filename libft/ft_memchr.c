#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *s;

	s = (unsigned char*)src;
	while (n-- > 0)
	{
		if (*s == (unsigned char)c)
			return ((void*)s);
		s++;
	}
	return (NULL);
}
