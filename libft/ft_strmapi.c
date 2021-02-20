#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(buf = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
