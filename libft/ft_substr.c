/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:54:40 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/09/14 15:42:14 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*str;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	str = ft_calloc(len + 1, sizeof(char));
	{
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
	}
	return (str);
}
/*
int	main(void)
{
	char s[] = "this is the one";
	char *str = ft_substr(s, 1, 5);
	puts(str);
	return (0);
}*/
