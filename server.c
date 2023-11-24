/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:33:04 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/24 20:05:44 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void binary_to_char(int signum, char *c)
{
   if (signum == SIGUSR1)
      *c = (*c << 1) | 1;
   else if(signum == SIGUSR2)
      *c <<= 1;
}



void signal_handler(int signum, siginfo_t *info, void *context)
{
   static int  pid = 0;
   static int  i = 0;
   static char c = 0;
   (void)context;

   pid = info -> si_pid;
   binary_to_char(signum, &c);
   if (++i == 8)
   {
      i = 0;
      if (!c)
      {
         kill(pid, SIGUSR1);
         pid = 0;
         return ;
      }
      write(STDOUT_FILENO, &c, 1);
      c = 0;
   }
   kill(pid, SIGUSR2);
}


int main(void)
{
   struct sigaction sa;
   ft_printf("Server PID: %d\n", getpid());
   ft_memset(&sa, 0, sizeof(sa));
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = signal_handler;
   sigemptyset(&sa.sa_mask);
   if (sigaction(SIGUSR1, &sa, NULL) == -1)
   {
      ft_printf("Error setting signal handler for SIGUSR1");
      return 1;
   }
   if (sigaction(SIGUSR2, &sa, NULL) == -1)
   {
      ft_printf("Error setting signal handler for SIGUSR2");
      return 1;
   }
   while (1)
   {
      pause();
   }
   return(0);
}
