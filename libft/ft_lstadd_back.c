#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pwd;

	if (new && *lst)
	{
		pwd = ft_lstlast((*lst));
		pwd->next = new;
		return ;
	}
	*lst = new;
}
