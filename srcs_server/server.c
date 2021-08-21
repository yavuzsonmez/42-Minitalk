/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/21 11:57:35 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_pid(void)
{
	ft_putstr_fd("\nSTARTING MINITALK SERVER ...\n", 1);
	ft_putstr_fd("____________________________\n", 1);
	ft_putstr_fd("\nPROCESS ID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

//static

static void ft_print_signal(int signum)
{
	(void)signum;
	ft_putstr_fd("Signal Received..\n", 1);
	
	
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
		signal(SIGUSR1, ft_print_signal);
		signal(SIGUSR2, ft_print_signal);
		/*
		if ()
			exit(EXIT_SUCCESS);
		*/
		pause();
	}
	return 0;
}