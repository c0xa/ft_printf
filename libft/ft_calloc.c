#include "libft.h"

char	*ft_calloc(size_t count, size_t size)
{
	void			*buf;
	unsigned char	*p;

	size = size * count;
	buf = malloc(size);
	if (!buf)
		return (0);
	p = buf;
	while (size-- > 0)
	{
		*(p++) = 0;
	}
	return (buf);
}
