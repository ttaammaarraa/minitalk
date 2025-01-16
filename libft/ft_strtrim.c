/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:45:39 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:57 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*create_trimmed_string(const char *s1, int start, int end)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_calloc((end - start + 2), sizeof(char));
	if (!new_str)
		return (NULL);
	while (start <= end)
	{
		new_str[i] = s1[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end], set))
		end--;
	return (create_trimmed_string(s1, start, end));
}
/*int	main(void)
{
	char s[] = "dhhhghgghgigdddd";
	char s1[] = "ggd";
	char *c;
	c = ft_strtrim(s, s1);
	puts(c);
	free(c);
	return (0);
}*/
