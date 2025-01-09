/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:21:12 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/10/05 17:33:51 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_handle_putchar(int c);
int	ft_handle_string(char *str);
int	ft_printnbr(int n);
int	ft_printf(const char *format, ...);
int	ft_print_hex(unsigned long num, const char format);
int	ft_handle_unsigned(unsigned int n);
int	ft_handle_ptr(void *ptr);

#endif
