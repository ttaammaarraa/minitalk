#include "libft.h"
/*  void    ft_del(void *content)
{
    content = NULL;
  
} */
void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *temp;

    temp = *lst;
    if(!lst)
        return ;
    while (*lst)
    {
        *lst = (*lst)->next;
        ft_lstdelone(temp, del);
        temp = *lst;
    }
}

/* int main()
{
    t_list *p, *q;
    int data = 500;
    int tt = 466;
    p = ft_lstnew(&data);
    q = ft_lstnew(&tt);
    ft_lstadd_back(&p, q);
    ft_lstclear(&p, ft_del);
} */