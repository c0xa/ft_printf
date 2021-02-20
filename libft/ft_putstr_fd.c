#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
