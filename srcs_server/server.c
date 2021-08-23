/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/23 17:59:57 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_byte byte;

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
	if (signum == SIGUSR2)
		signum = 0;
	else if (signum == SIGUSR1)
		signum = 1;

		/*
	if (byte.i && byte.i == 0)
	{
		byte.arr = (int *)malloc(sizeof(int) * (8 + 1));
		if (byte.arr == NULL)
			return ;
		byte.arr[8] = '\0';
	}
	byte.arr[byte.i] = signum;
	if (byte.i == 8)
	{
		//ft_decode(str);
		ft_memfree(byte.arr);
	}
	*/
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
		if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
		{
			ft_putendl_fd("An error has occurred", 1);
			exit(EXIT_FAILURE);
		}
		/*
		if (byte.arr != NULL)
		{
			ft_putendl_fd("Signal Received..", 1);
			ft_putnbr_fd(byte.arr[0], 1);
			ft_putnbr_fd(byte.arr[1], 1);
			ft_putnbr_fd(byte.arr[2], 1);
			ft_putnbr_fd(byte.arr[3], 1);
		}
		*/
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