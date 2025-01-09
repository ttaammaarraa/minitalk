/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:05:10 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/09/07 14:00:59 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*ss;

	i = 0;
	ss = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (ss[i] == cc)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
