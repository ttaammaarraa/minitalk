#include "libft.h"
//#include<stdio.h>
void    ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!new)
        return ;
    new->next = *lst;
    *lst = new;
}

/*int main()
{
    t_list *p1;
    t_list *p2;
    int data;
    int data2;

    data2 = 5;
    data = 10;
    p1 = malloc(sizeof(t_list));
    p2 = malloc(sizeof(t_list));
    p1->content = &data;
    p1->next = NULL;
    p2->content = &data2;
    p2->next = NULL;
    ft_lstadd_front(&p1, p2);
    while (p2)
    {
        printf("%d\n", *(int *)p2->content);
        
        p2= p2->next;
    }
}*/