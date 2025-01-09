/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:02:30 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/09/17 17:09:41 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	cc;

	temp_b = (unsigned char *) b;
	cc = (unsigned char)c;
	while (len > 0)
	{
		*temp_b = cc;
		temp_b++;
		len--;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[] = "Helllooo h fif";

	ft_memset(str, 'f', 6);
	puts(str);
	return (0);
}*/
