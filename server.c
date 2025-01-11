#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"


/*void    handle(int sig)
{
  static unsigned char character = 0;
    static int bit_position = 0;

    if (sig == SIGUSR1)
        character |= (1 << bit_position);
    else if (sig == SIGUSR2)
        character &= ~(1 << bit_position);

    bit_position++;
    if (bit_position == 8) // Assuming you print the character after 8 bits
    {
        ft_printf("%c", character);
        character = 0;
        bit_position = 0;
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
}*/

#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"


typedef struct s_server_state
{
    char *buffer;          
    size_t length;       
} t_server_state;

t_server_state g_state = {NULL, 0}; 

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

    if (new_size == 0) 
    {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL; 
    if (ptr)
    {
        ft_memcpy(new_ptr, ptr, old_size);
        free(ptr);
    }
    return new_ptr;
}

void handle(int sig)
{
    static unsigned char character = 0; 
    static int bit_position = 0;
    if (sig == SIGUSR1)
        character |= (1 << bit_position);
    else if (sig == SIGUSR2)
        character &= ~(1 << bit_position);

    bit_position++;

    if (bit_position == 8)
    {
        bit_position = 0;

        if (character == '\0') 
        {
            if (g_state.buffer)
            {
                ft_printf("Received string: %s\n", g_state.buffer);
                free(g_state.buffer); 
                g_state.buffer = NULL; 
                g_state.length = 0;
            }
        }
        else
        {
            char *new_buffer = ft_realloc(g_state.buffer, g_state.length, g_state.length + 2); // +2 for new char and null terminator
            if (!new_buffer)
            {
                ft_printf("Memory allocation error\n");
                exit(1);
            }
            g_state.buffer = new_buffer;
            g_state.buffer[g_state.length++] = character;
            g_state.buffer[g_state.length] = '\0';
        }
        character = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    ft_printf("Server PID: %d\n", getpid());

    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handle;
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("ERROR: Could not set SIGUSR1 handler\n");
        return (1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("ERROR: Could not set SIGUSR2 handler\n");
        return (1);
    }

    while (1)
        pause();
}