/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:34:42 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/10/06 17:32:15 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(const char *format, va_list arg)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_handle_putchar(va_arg(arg, int));
	else if (*format == 's')
		count += ft_handle_string(va_arg(arg, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_printnbr(va_arg(arg, int));
	else if (*format == 'x' || *format == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), *format);
	else if (*format == 'u')
		count += ft_handle_unsigned(va_arg(arg, unsigned int));
	else if (*format == '%')
		count += write(1, format, 1);
	else if (*format == 'p')
		count += ft_handle_ptr(va_arg(arg, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			count;

	va_start (arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_format(format, arg);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (count);
}

