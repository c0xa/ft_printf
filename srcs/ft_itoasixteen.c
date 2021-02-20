#include "ft_printf.h"

size_t		sizesixteen(unsigned long long digit, int base)
{
	size_t len;

	len = 0;
	if (digit == 0)
		return (1);
	while (digit)
	{
		digit /= base;
		len++;
	}
	return (len);
}

char		*ft_itoasixteen(unsigned long long digit, int base)
{
	unsigned long long		num;
	char					*buf;
	size_t					len;

	len = sizesixteen(digit, base);
	if (!(buf = (char*)malloc(len + 1 * (sizeof(char)))))
		return (NULL);
	*(buf + len) = '\0';
	while (len--)
	{
		num = digit % base;
		if (num > 9)
			*(buf + len) = num + 87;
		else
			*(buf + len) = num + 48;
		digit /= base;
	}
	return (buf);
}
