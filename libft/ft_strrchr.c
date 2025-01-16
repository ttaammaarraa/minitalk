/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:25:07 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:55 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	cc;
	int		i;

	cc = (char)c;
	res = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			res = (char *)&s[i];
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	return (res);
}
/*#include <stdio.h>

// Function prototype for ft_strrchr
char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	const char *str1 = "Hello, world!";
	int ch1 = 'o';
	int ch2 = 'x';
	int ch3 = '\0';

	// Test case 3: Special case where character is the null terminator
	char *result3 = ft_strrchr(str1, ch3);
	if (result3)
		printf("Last occurrence of '\\0' in \"%s\" is at: %s\n", str1, result3);
	else
		printf("Null terminator not found in \"%s\"\n", str1);

	return (0);
}*/
