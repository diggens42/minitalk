/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:51 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/24 20:54:42 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t g_receiver = 0;


void	signal_handler(int signum, siginfo_t *info, void *context)
{
    static int i = 0;
    (void)info;
    (void)context;
    
    if (signum == SIGUSR1)
    {
        i++;
	}
    else if (signum == SIGUSR2)
    {
        g_receiver = 1;
        ft_printf("Number of bytes received: %d\n", i / 8);
        // exit(0);
    }
}

int char_to_binary(char c, int pid)
{
	int i;
    int bit_idx;

    bit_idx = 7;
    while (bit_idx >= 0)
    {
        i = 0;
        if ((c >> bit_idx & 1))
        {
            if(kill(pid, SIGUSR1) == -1)
            {
                ft_printf("Error sending SIGUSR1");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if(kill(pid, SIGUSR2) == -1)
            {
                ft_printf("Error sending SIGUSR2");
                exit(EXIT_FAILURE);
            }
        }
        g_receiver = 0;
        while (g_receiver == 0)
        {
            if (i == 100)
            {
                ft_printf("No response from server\n");
                exit(EXIT_FAILURE);
            }
            i++;
            usleep(1000);
        }
        g_receiver = 0;
        bit_idx--;
    }
    return(0);
}

void    error_handler(int argc)
{
    if (argc != 3)
    {
        ft_printf("Invalid number of arguments");
        exit(EXIT_FAILURE);
    }
}

int	main(int argc, char **argv)
{
	pid_t   server_pid;
    struct  sigaction sa;
    int     i;
    
    error_handler(argc);
    server_pid = ft_atoi(argv[1]);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    if(sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Error setting signal handler");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while(argv[2][i] != '\0')
    {
        char_to_binary(argv[2][i], server_pid);
        i++;
    }
    char_to_binary('\0', server_pid);
    return(0);
}
