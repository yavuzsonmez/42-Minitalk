/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/23 15:53:00 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int bits;

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
	ft_putendl_fd("\nStarting Minitalk server...", 1);
	ft_putendl_fd("____________________________", 1);
	ft_putstr_fd("\nProcess ID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

static void ft_print_signal(int signum)
{
	//char *str;
	int byte[9];
	int i;

	i = 0;
	if (signum == SIGUSR2)
		signum = 0;
	else if (signum == SIGUSR1)
		signum = 1;
	//ft_putendl_fd("Signal Received..", 1);
	ft_putnbr_fd(signum, 1);
	//if (bits == 0)
	//	str = (char *)malloc(sizeof(char) * (8 + 1));
	//str[bits] = signum;
	//if (bits == 8)
	//{
	//	str[bits] = '\0';
	//	ft_decode(str);
	//
	//	free(str);
	//}
}

int main(void)
{
	struct sigaction act;

	ft_pid();
	//ft_memset(&act, '\0', sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_handler = &ft_print_signal;
	while (1)
	{
		if (sigaction(SIGUSR1, &act, NULL) < 0)
		{
			ft_putendl_fd("An error has occurred", 1);
			exit(EXIT_FAILURE);
		}
		else if (sigaction(SIGUSR2, &act, NULL) < 0)
		{
			ft_putendl_fd("An error has occurred", 1);
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return (0);
}

//if (!ft_strncmp(str, "exit", 5))
//{
//	ft_memfree(str);
//	exit(EXIT_SUCCESS);
//}
//ft_putendl_fd(str, 1);
//ft_memfree(str);