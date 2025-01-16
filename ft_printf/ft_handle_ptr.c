/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:27:34 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:28:43 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_ptr(void *ptr)
{
	int	c;	

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	c = 2 + ft_print_hex((unsigned long)ptr, 'x');
	return (c);
}
// Prefix for pointer addresses in hexadecimal
// Provide 'x' for lowercase hex
