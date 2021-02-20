#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (len > 0)
	{
		*p++ = (char)c;
		len--;
	}
	return (b);
}
