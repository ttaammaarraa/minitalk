#include "libft.h"
/* #include <stdio.h>
void     sum(void *content)
{
    *(int *) content += 1;
} */
void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    while(lst)
    {
        (*f)(lst->content);
        lst = lst->next;
    }
}

/* int main()
{
    int data = 10;
    t_list *p = ft_lstnew(&data);
    int data2 = 50;
    t_list *s = ft_lstnew(&data2);
    p->next = s;
    ft_lstiter(p, sum);
    printf("%d\n" , *(int *)p->content);
    printf("%d" , *(int *)s->content);
}
 */