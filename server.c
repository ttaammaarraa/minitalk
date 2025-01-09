#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"


void    handle(int sig)
{
    int flag;
    if (sig == SIGUSR1)
    {
        
    }
    else if (sig == SIGUSR2)
    {

    }
    else
        return ;
}

int main (void)
{
    struct sigaction sa;

    ft_printf("%d\n", getpid());
    
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handle;
    sa.sa_flags = 0;
    
    
    if(sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("ERORR");
        return (1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("ERROR");
        return (1);
    }


    while(1)
        pause();
}