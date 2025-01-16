/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:26:06 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:07 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* #include <stdio.h>
void	sum(void *content)
{
	*(int *) content += 1;
} */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* int main()
{
	int		data;
	t_list	*p;
	int		data2;
	t_list	*s;

	data = 10;
	p = ft_lstnew(&data);
	data2 = 50;
	s = ft_lstnew(&data2);
	p->next = s;
	ft_lstiter(p, sum);
	printf("%d\n" , *(int *)p->content);
	printf("%d" , *(int *)s->content);
}
 */