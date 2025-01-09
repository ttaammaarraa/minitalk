/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:13:52 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/10/05 18:00:01 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_hex(unsigned long num, const char format)
{
	char	*hex_lower;
	char	*hex_upper;
	char	*hex;
	int		write_i;	

	write_i = 0;
	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (format == 'x')
		hex = hex_lower;
	else
		hex = hex_upper;
	if (num >= 16)
		write_i += ft_print_hex(num / 16, format);
	write_i += write(1, &hex[num % 16], 1);
	return (write_i);
}
