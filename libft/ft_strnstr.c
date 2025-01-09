/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:29:13 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/09/14 17:11:58 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;

	if (needle[0] == '\0')
		return ((char *)haystack);
	c = ft_strlen(needle);
	while (*haystack && c <= len)
	{
		if (!(ft_strncmp((char *)haystack, (char *)needle, c)))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*#include <stdio.h>
int main() {
    char haystack[] = "Hello, world!";
    char needle[] = "world";
    size_t len = 12;

    char *result = ft_strnstr(haystack, needle, len);

    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}*/
