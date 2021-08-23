/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/23 09:36:20 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_pid(void)
{
	ft_putendl_fd("\nSTARTING MINITALK SERVER ...", 1);
	ft_putendl_fd("____________________________", 1);
	ft_putstr_fd("\nPROCESS ID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

//static

static void ft_print_signal(int signum)
{
	if (signum == SIGUSR2)
		signum = 0;
	else if (signum == SIGUSR1)
		signum = 1;
	ft_putendl_fd("Signal Received..", 1);
	ft_putnbr_fd(signum, 1);


}

int main(void)
{
	ft_pid();
	//struct sigaction action;
//
	//action.sa_handler = ft_print_signal();
	//sigemptyset(&action.sa_mask);
	//action.sa_flags = 0;

	while(1)
	{
		//sigaction();
		if (signal(SIGUSR1, ft_print_signal) == SIG_ERR || signal(SIGUSR2, ft_print_signal) == SIG_ERR)
		{
			ft_putendl_fd("An error has occurred", 1);
			exit(EXIT_FAILURE);
		}
		pause();
	}
	exit(EXIT_SUCCESS);
	return (0);
}