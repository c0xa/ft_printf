#include "ft_printf.h"

int			ft_istype(char s, va_list args, t_flags *flags)
{
	int count;

	count = 0;
	if (s == 'c')
		count = ft_ischar(va_arg(args, int), flags, 0, 0);
	else if (s == 's')
		count = ft_isstring(va_arg(args, char *), flags, 0, 1);
	else if (s == 'd' || s == 'i')
		count = ft_isinteger(va_arg(args, int), flags, 1, 1);
	else if (s == 'u')
		count = ft_isunsignedint((unsigned int)va_arg(args, unsigned int),
		1, 1, flags);
	else if (s == 'p')
		count = ft_ispointer(va_arg(args, unsigned long long), flags);
	else if (s == 'x')
		count = ft_ishexadecimallower(va_arg(args, unsigned int), 1, 1, flags);
	else if (s == 'X')
		count = ft_ishexadecimalupper(va_arg(args, unsigned int), 1, 1, flags);
	else if (s == '%')
		count = ft_printprocent(flags);
	return (count);
}

int			ft_isflag(const char **c, t_flags *flags, va_list args)
{
	const char	*p;

	p = *c;
	while (*p && (ft_flag(*p) || ft_isdigit(*p)))
	{
		if (*p == '-')
			p = ft_minus(p, flags, args);
		else if (*p == '0')
			p = ft_zero(p, flags, args);
		else if (*p == '.')
			p = ft_dot(p, flags, args);
		else if (*p == '*' || ft_isdigit(*p))
			p = ft_star(p, flags, args);
		else if (*p == ' ')
		{
			while (*p == ' ')
				p++;
			ft_putchar_fd(' ', 1);
		}
		else
			write(1, p, 1);
	}
	*c = p;
	return (ft_istype(*p, args, flags));
}

int			ft_parse_copy(const char *s, va_list args)
{
	int			count_char;
	t_flags		flags;

	count_char = 0;
	while (*s)
	{
		flags = initial();
		if (*s == '%' && *(s + 1))
		{
			s++;
			if (ft_flag(*s) || ft_isdigit(*s) || ft_type(*s))
				count_char += ft_isflag(&s, &flags, args);
			else
				return (-1);
		}
		else
		{
			write(1, s, 1);
			count_char++;
		}
		s++;
	}
	return (count_char);
}

int			ft_printf(const char *str, ...)
{
	va_list		args;
	int			char_count;

	char_count = 0;
	va_start(args, str);
	char_count = ft_parse_copy(str, args);
	va_end(args);
	return (char_count);
}
