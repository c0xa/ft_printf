#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *))
{
	t_list *pwd;
	t_list *element;

	if (!lst || !(pwd = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if (!(element = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&pwd, del);
			return (NULL);
		}
		ft_lstadd_back(&pwd, element);
		lst = lst->next;
	}
	return (pwd);
}
