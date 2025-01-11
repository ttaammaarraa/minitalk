#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void    send(int pid, char *str)
{
    int i;
    int j;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (j < 8)
        {
            if (((str[i] >> j) & 1))
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(500);
            j++;
        }
        i++;
    }
    j = 0;
    while (j < 8)
    {
        kill(pid, SIGUSR2); 
        usleep(500);
        j++;
    }
}


int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
    {
        ft_printf("wrong number of arguments");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    send(pid, argv[2]);
    ft_printf("sending signals");
}
