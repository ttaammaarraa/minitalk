#include "libft.h"
/* void    ft_del(void *content)
{
    content = NULL;
  
}
 */
void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    del(lst->content);
    free(lst);
}
/* int main()
{
    t_list *p;
    int data = 10;
    p = malloc(sizeof(t_list));
    
    p->content = &data;
    p->next = NULL;
    ft_lstdelone(p, ft_del);
} */