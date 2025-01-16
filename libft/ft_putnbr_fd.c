/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:33:13 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:30 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = ((n % 10) + '0');
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	// Open a file to write the output
	//(creates a file "output.txt" if it doesn't exist)
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	// Check if the file opened successfully
	if (fd == -1)
	{
		write(2, "Error opening file\n", 19);
		return (1);
	}

	// Test with different integers
	ft_putnbr_fd(42, fd);       // Writes "42"
	write(fd, "\n", 1);         // Newline for clarity
	ft_putnbr_fd(-123456, fd);  // Writes "-123456"
	write(fd, "\n", 1);         // Newline for clarity
	ft_putnbr_fd(0, fd);        // Writes "0"
	write(fd, "\n", 1);         // Newline for clarity
	ft_putnbr_fd(-2147483648, fd); // Writes "-2147483648"
	write(fd, "\n", 1);         // Newline for clarity

	// Close the file descriptor
	close(fd);

	return (0);
}*/
