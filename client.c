/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:24:17 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/16 10:30:36 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int g_sig = 0;

void	sig_handle (int sig)
{
	if (sig == SIGUSR1)
		g_sig = 1;
}
void send(char *str, int pid)
{
    int i;
    int j;
    int ch;

    i = 0;
    while (str[i])
    {
        j = 0;
        while (j < 8)
        {
            ch = (str[i] >> j) & 1; // Extract the bit to send
            g_sig = 0; // Reset acknowledgment flag before sending the bit

            if (ch == 0)
                kill(pid, SIGUSR1); // Send SIGUSR1 for 0
            else
                kill(pid, SIGUSR2); // Send SIGUSR2 for 1

            while (!g_sig) // Wait until acknowledgment is received
                ;
            
            j++;
        }
        i++;
    }

    // Send null terminator
    j = 0;
    while (j < 8)
    {
        g_sig = 0; // Reset acknowledgment flag before sending the bit
        kill(pid, SIGUSR1); // Send SIGUSR1 for null terminator (always 0 bits)

        while (!g_sig) // Wait until acknowledgment is received
            ;
        
        j++;
    }
}

	
int	main(int argc ,char **argv)
{
	int pid;
	
	if (argc != 3)
		return (1);
	struct sigaction sa;

	sa.sa_flags = 0;
	sa.sa_handler = sig_handle;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	pid = ft_atoi(argv[1]);
	send(argv[2], pid);
	
}