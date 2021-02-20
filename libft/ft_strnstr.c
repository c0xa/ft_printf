#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			k = 1;
			while (needle[k] && haystack[i + k] == needle[k] && (i + k) < len)
				k++;
			if (!needle[k])
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (0);
}
