/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:46:42 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:46 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (dstsize > 0)
	{
		if (len_src + 1 < dstsize)
			ft_memcpy(dst, src, len_src + 1);
		else
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (len_src);
}
/*int	main(void)
{
	char	src[] = "Hello my brothers";
	char	dest[] = "dofertert";

	ft_strlcpy(dest, src, 6);
	puts(dest);
	return (0);
}*/
