/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:26:04 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:05 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void    ft_del(void *content)
{
	content = NULL;
}
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
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