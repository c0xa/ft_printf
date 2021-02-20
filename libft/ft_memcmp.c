#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (c1[i] == c2[i] && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((int)(c1[i] - c2[i]));
}
