#include "libft.h"
//#include <stdio.h>
int ft_lstsize(t_list *lst)
{
    int count;

    count = 0;
    while (lst)
    {
        count++;
        lst=lst->next;
    }
    return (count);
}

/* int main()
{
    int data;
    t_list *p;

    data = 10;
    p = ft_lstnew(&data);
    data = ft_lstsize(p);
    printf("%d", data);
} */