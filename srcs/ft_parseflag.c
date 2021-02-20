#include "ft_printf.h"

const char		*ft_minus(const char *d, t_flags *flags, va_list args)
{
	int c;

	c = 0;
	d++;
	if (ft_isdigit(*d) && *d)
	{
		c += *d - '0';
		d++;
		while (ft_isdigit(*d) && *d)
		{
			c = c * 10 + (*d - '0');
			d++;
		}
	}
	else if (*d == '*')
	{
		c = va_arg(args, int);
		d++;
	}
	if (c < 0)
		c *= -1;
	flags->minus = c;
	return (d);
}

const char		*ft_zero(const char *d, t_flags *flags, va_list args)
{
	int c;

	c = 0;
	d++;
	if (ft_isdigit(*d) && *d)
	{
		c += *d - '0';
		d++;
		while (ft_isdigit(*d) && *d)
		{
			c = c * 10 + (*d - '0');
			d++;
		}
	}
	else if (*d == '*')
	{
		c = va_arg(args, int);
		d++;
	}
	flags->zero = c;
	return (d);
}

const char		*ft_dot(const char *d, t_flags *flags, va_list args)
{
	int c;

	c = 0;
	d++;
	if (ft_isdigit(*d) && *d)
	{
		c += *d - '0';
		d++;
		while (ft_isdigit(*d) && *d)
		{
			c = c * 10 + (*d - '0');
			d++;
		}
	}
	else if (*d == '*')
	{
		c = va_arg(args, int);
		d++;
	}
	if (c < 0)
		c = -1;
	flags->dot = c;
	return (d);
}

const char		*ft_star(const char *d, t_flags *flags, va_list args)
{
	int c;

	c = 0;
	if (ft_isdigit(*d) && *d)
	{
		c += *d - '0';
		d++;
		while (ft_isdigit(*d) && *d)
		{
			c = c * 10 + (*d - '0');
			d++;
		}
	}
	else if (*d == '*')
	{
		c = va_arg(args, int);
		d++;
	}
	flags->minus = -1 * c;
	return (d);
}
