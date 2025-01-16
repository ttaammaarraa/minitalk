/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:25:56 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:27:55 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  void    ft_del(void *content)
{
	t_list	*temp;

	content = NULL;
} */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (!lst)
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