/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/20 19:22:53 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_pid(void)
{
	ft_putstr_fd("MINITALK SERVER..\n", 1);
	ft_putstr_fd("PROCESS ID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

//static

static void ft_print_signal(int k)
{
	if (k < 0)
		return ;
	ft_putstr_fd("test\n", 1);
}

int main(void)
{
	ft_pid();
	//struct sigaction action;
//
	//action.sa_handler = ft_print_signal();
	//sigemptyset(&action.sa_mask);
	//action.sa_flags = 0;


	int signum;
	while(1)
	{
		signum = pause();
		ft_putstr_fd("Signal Received..\n", 1);
		//sigaction();
		signal(signum, &ft_print_signal);
		/*
		if ()
			exit(EXIT_SUCCESS);
		*/
	}
	return 0;
}