#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *pwd;

	pwd = *lst;
	while (pwd)
	{
		pwd = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = pwd;
	}
}
