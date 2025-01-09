/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:07:13 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/09/04 18:07:25 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(int argc, char **argv)
{
	char	s[] = "Hello Hala";

	ft_bzero(s, 6);
	for (int i = 0; i < 10; i++)
	{
		printf("%c", s[i]);
	}
	return (0);
}*/
