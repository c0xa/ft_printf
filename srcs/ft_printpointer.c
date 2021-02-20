#include "ft_printf.h"

int		ft_minus_pointer(char *s, int minus, int lenc, int i)
{
	i = minus * (minus > 0 ? 1 : -1);
	if (i < (int)(ft_strlen(s)))
	{
		ft_putstr_fd(s, 1);
		return (0);
	}
	else if (minus > 0)
	{
		i = minus - ft_strlen(s);
		ft_putstr_fd(s, 1);
		lenc = i;
		while (i-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if ((minus < 0))
	{
		i = (minus * -1) - ft_strlen(s);
		lenc = i;
		while (i-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(s, 1);
	}
	return (lenc);
}

int		ft_ispointer(unsigned long long un, t_flags *flags)
{
	char	*s;
	int		lens;
	char	*res;

	lens = 0;
	if (flags->dot == 0 && un == 0)
		res = ft_strdup("");
	else
		res = ft_itoasixteen(un, 16);
	s = ft_strjoin("0x", res);
	free(res);
	lens = ft_strlen(s);
	if (flags->minus != 0)
		lens += (ft_minus_pointer(s, flags->minus, 0, 0));
	else
		ft_putstr_fd(s, 1);
	free(s);
	return (lens);
}
