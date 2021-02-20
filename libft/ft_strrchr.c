#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == (char)ch)
			return ((char*)str + len);
		len--;
	}
	return (0);
}
