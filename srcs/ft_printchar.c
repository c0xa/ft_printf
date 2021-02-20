#include "ft_printf.h"

int		ft_minusbon(char **res, int flag, int t, int *i)
{
	*res = ft_itminus(*res, t);
	*i = -1;
	return (ft_minus_pointer(*res, flag, 0, 0));
}

int		ft_ischar(char c, t_flags *flags, int lenc, int i)
{
	if (flags->minus > 0)
	{
		i = flags->minus;
		ft_putchar_fd(c, 1);
		lenc = i--;
		while (i-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if ((flags->minus < 0))
	{
		i = (flags->minus * -1);
		lenc = i--;
		while (i-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		lenc = 1;
	}
	return (lenc);
}
