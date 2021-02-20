#include "ft_printf.h"

char			*ft_dotzero(size_t flag, char *c, size_t lens)
{
	char		*v;
	char		*res;
	size_t		j;

	j = 0;
	if (flag > lens)
		lens = flag - lens;
	else
		return (c);
	if (!(v = (char*)malloc((lens * (sizeof(char))))))
		return (NULL);
	while (lens > j++)
		v[j - 1] = '0';
	v[j - 1] = '\0';
	res = ft_strjoin(v, c);
	free(v);
	free(c);
	return (res);
}

char			*ft_itminus(char *res, int t)
{
	char *c;

	if (!t)
		return (res);
	c = ft_strjoin("-", res);
	free(res);
	return (c);
}

static char		*ft_dotnil(int n, char *res)
{
	if (n == 0)
	{
		free(res);
		res = ft_strdup("");
	}
	return (res);
}

static char		*ft_put(char *res, int t)
{
	res = ft_itminus(res, t);
	ft_putstr_fd(res, 1);
	return (res);
}

int				ft_isinteger(int d, t_flags *flags, size_t lens, int i)
{
	char	*res;
	int		t;

	t = (d < 0 ? 1 : 0);
	if (!(res = (ft_itoa(d))))
		return (0);
	if (flags->dot >= (int)ft_strlen(res) && flags->dot > 0)
		res = ft_dotzero(flags->dot, res, ft_strlen(res));
	else if (flags->dot == 0)
		res = ft_dotnil(d, res);
	if ((flags->dot >= 0 && flags->zero > 0) || (flags->zero < 0))
		flags->minus = flags->zero * -1;
	i = flags->minus * (flags->minus < 0 ? -1 : 1);
	if (flags->minus != 0 && i > (int)ft_strlen(res))
		lens += ft_minusbon(&res, flags->minus, t, &i);
	else if (flags->zero > (int)lens && flags->zero > 0)
		res = ft_dotzero(flags->zero, res, ft_strlen(res) + t);
	if (i != -1)
		res = ft_put(res, t);
	lens += ft_strlen(res);
	free(res);
	return ((int)lens - 1);
}
