#include "libft.h"

int		ft_strncmp(const char *string1, const char *string2, size_t num)
{
	unsigned char *s1;
	unsigned char *s2;

	if (num == 0)
		return (0);
	s1 = (unsigned char *)string1;
	s2 = (unsigned char *)string2;
	num--;
	while (num != 0 && *s1 && *s2 && *s1 == *s2)
	{
		num--;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
