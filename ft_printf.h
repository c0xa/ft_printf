/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblink <tblink@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:02 by tblink            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:16 by tblink           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int		minus;
	int		zero;
	int		dot;
}				t_flags;

int				ft_printf(const char *str, ...);
int				t_parse_copy(const char *s, va_list args);
int				ft_type(char s);
int				ft_flag(char s);
int				ft_istype(char s, va_list args, t_flags *flags);
int				ft_isflag(const char **c, t_flags *flags, va_list args);
int				ft_isstring(char *s, t_flags *flags, int i, int lens);
int				ft_ischar(char c, t_flags *flags, int lenc, int i);
int				ft_isinteger(int d, t_flags *flags, size_t lens, int i);
int				ft_isunsignedint(unsigned int un, int i,
				size_t lens, t_flags *flags);
int				ft_ispointer(unsigned long long un, t_flags *flags);
char			*ft_itoasixteen(unsigned long long digit, int base);
int				ft_ishexadecimallower(unsigned long long un, int i,
				size_t lens, t_flags *flags);
int				ft_ishexadecimalupper(unsigned long long un, int i,
				size_t lens, t_flags *flags);
char			*ft_itoasixteenlupper(unsigned long long digit);
int				ft_printprocent(t_flags *flags);
const char		*ft_minus(const char *d, t_flags *flags, va_list args);
const char		*ft_dot(const char *d, t_flags *flags, va_list args);
const char		*ft_zero(const char *d, t_flags *flags, va_list args);
const char		*ft_star(const char *d, t_flags *flags, va_list args);
int				ft_minus_pointer(char *s, int minus, int lenc, int i);
int				ft_minusbon(char **res, int flag, int t, int *i);
char			*ft_dotzero(size_t flag, char *c, size_t lens);
char			*ft_itminus(char *res, int t);
size_t			sizesixteen(unsigned long long digit, int base);
t_flags			initial(void);
#endif
