/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:30:43 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/16 10:31:39 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void    *str;

    str = malloc (new_size);
    if (!str)
    {
        free (ptr);
        return (NULL);
    }
    ft_memcpy(str, ptr, old_size);
    free (ptr);
    return (str);
}

void    signal_handler(int sig, siginfo_t *info, void *content)
{
    static char chr = 0;
    static int  bit = 0;
    static char *ptr = NULL;
    static size_t size = 0;    
    static size_t capacity = 0; 

    (void)content;
    if (sig == SIGUSR2)
        chr |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        bit = 0;
        if (capacity == size)
        {
            if (capacity == 0)
                capacity = 1024;
            else
                capacity *= 2;
            ptr = ft_realloc(ptr, size, capacity);
            if(!ptr)
                exit(EXIT_FAILURE);
        }
        ptr[size++] = chr;
        chr = 0;
        if (ptr[size - 1] == '\0')
        {
            ft_putstr_fd("RECIEVED MESSAGE\n", 1);
            ft_putstr_fd(ptr, 1);
            free(ptr);  
            ptr = NULL; 
            size = 0;  
            capacity = 0;
        }
        kill(info->si_pid, SIGUSR1);
    }
}

int main()
{
    struct sigaction    sa;
    
    ft_printf("%d\n", getpid());
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        return (1);
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        return (1);
    while (1)
        pause();
    return (0); 
}
