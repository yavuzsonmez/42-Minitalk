/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/23 13:46:26 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
/*
static int	ft_iterative_power(int nb, int power)
{
	int i;
	int k;

	i = 1;
	k = nb;
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	if (power == 0 && nb == 0)
		return (1);
	if (power == 0)
		return (1);
	while (i < power)
	{
		k = k * nb;
		i++;
	}
	return (k);
}
*/

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
	//char *str;

	if (signum == SIGUSR2)
		signum = 0;
	else if (signum == SIGUSR1)
		signum = 1;
	//ft_putendl_fd("Signal Received..", 1);
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
		struct sigaction act;

		ft_memset(&act, '\0', sizeof(act));
		act.sa_handler = &ft_print_signal;

		if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
		{
			ft_putendl_fd("An error has occurred", 1);
			exit(EXIT_FAILURE);
		}

		//if (!ft_strncmp(str, "exit", 5))
		//{
		//	ft_memfree(str);
		//	exit(EXIT_SUCCESS);
		//}
		//ft_putendl_fd(str, 1);
		//ft_memfree(str);
		pause();
	}
	return (0);
}