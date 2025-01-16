/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:11:07 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:37 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_mem(char **str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

static int	count_words(char const *s, char c)
{
	int	inside_word;
	int	count;

	count = 0;
	inside_word = 0;
	while (*s)
	{
		if (*s != c && inside_word == 0)
		{
			inside_word = 1;
			count++;
		}
		else if (*s == c)
			inside_word = 0;
		s++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	cpy_word(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	i = 0;
	str = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			str[i] = ft_calloc(word_len(s, c) + 1, sizeof(char));
			if (!str[i])
			{
				free_mem(str);
				return (NULL);
			}
			cpy_word(str[i++], s, word_len(s, c));
			s += word_len(s, c);
		}
	}
	return (str);
}
/*
int	main(void)
{
	const char *test_strings[] = {
		"hello,world,how,are,you",
		"apple,,banana,,cherry",
		"   spaces   between   words   ",
		"nodelimiter",
		",,,start,and,end,with,empty,,",
		""
	};
	const char delimiters[] = {',', ',', ' ', ',', ',', ','};
	const int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

	for (int t = 0; t < num_tests; t++)
	{
		printf("Test %d:\n", t + 1);
		printf("Input string: \"%s\"\n", test_strings[t]);
		printf("Delimiter: '%c'\n", delimiters[t]);

		char **result = ft_split(test_strings[t], delimiters[t]);

		if (result)
		{
			printf("Split result:\n");
			for (int i = 0; result[i] != NULL; i++)
			{
				printf("[%d]: \"%s\"\n", i, result[i]);
			}
			free_mem(result);
		}
		else
		{
			printf("Split failed or returned NULL\n");
		}
		printf("\n");
	}

	return (0);
}*/
