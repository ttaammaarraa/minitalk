/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:30:56 by taabu-fe          #+#    #+#             */
/*   Updated: 2024/10/05 11:31:39 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_handle_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
