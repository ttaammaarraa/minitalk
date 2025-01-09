#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *p;

    p = malloc(sizeof(t_list));
    if(!p)
        return (NULL);
    p->content = content;
    p->next = NULL;
    return (p);
}
/* 
int main()
{
    int data;
    t_list *p;

    data = 10;
    p = ft_lstnew(&data);
    printf("%d", *(int *)p->content);
} */