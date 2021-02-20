#include "ft_printf.h"

t_flags		initial(void)
{
	t_flags new;

	new.minus = 0;
	new.dot = -1;
	new.zero = 0;
	return (new);
}

int			ft_type(char s)
{
	return (s == 'c' || s == 's' || s == 'p' ||
			s == 'd' || s == 'i' || s == 'u' || s == 'x' ||
			s == 'X' || s == '%');
}

int			ft_flag(char s)
{
	return (s == '-' || s == '.' || s == '*' || s == '0' || s == ' ');
}

int			ft_printprocent(t_flags *flags)
{
	char	*s;
	int		lens;

	if (!(s = ft_strdup("%")))
		return (0);
	if (flags->zero > 0)
		s = ft_dotzero(flags->zero, s, 1);
	lens = ft_strlen(s);
	if ((flags->dot >= 0 && flags->zero > 0) || (flags->zero < 0))
		flags->minus = flags->zero * -1;
	if (flags->minus != 0)
		lens += ft_minus_pointer(s, flags->minus, 0, 0);
	else
		ft_putstr_fd(s, 1);
	free(s);
	return (lens);
}
