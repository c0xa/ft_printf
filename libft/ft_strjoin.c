#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*buf;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(buf = (char*)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	while (len1--)
	{
		buf[i] = s1[i];
		i++;
	}
	while (len2--)
	{
		buf[i] = *s2++;
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
