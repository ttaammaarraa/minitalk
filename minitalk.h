/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:58:23 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/14 17:09:22 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <signal.h>
# include <stdlib.h>

typedef struct s_server_state
{
	char	*buffer;
	size_t	length;
}			t_server_state;

#endif