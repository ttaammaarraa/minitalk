/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:25:10 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:27:27 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*int main()
{
	t_list *p1;
	t_list *p2;
	int data;
	int data2;

	p1 = malloc(sizeof(t_list));
	p2 = malloc(sizeof(t_list));
	data = 5;
	data2 = 10;
	p1->content = &data;
	p1->next = NULL;
	p2->content = &data2;
	p2->next = NULL;
	ft_lstadd_back(&p2, p1);
		while (p2)
	{
		printf("%d\n", *(int *)p2->content);

		p2= p2->next;
	}
}*/