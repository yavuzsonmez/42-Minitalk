/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/24 18:34:45 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_pid(void)
{
	ft_putendl_fd("\nStarting Minitalk server...", 1);
	ft_putstr_fd("\nProcess ID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("____________________________", 1);
}

static void ft_print_signal(int signum)
{
	static char c;
	static size_t size;

	if (signum == SIGUSR2)
		signum = 0;
	else if (signum == SIGUSR1)
		signum = 1;
	if (c == 0 && size == 0)
		size = 7;
	size--;
	c += (signum & 1) << size;
	if (size == 0)
	{
		if (!c)
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(c, 1);
		size = 7;
		c = 0;
	}
}

int main(void)
{
	struct sigaction act;

	ft_pid();
	sigemptyset(&act.sa_mask);
	act.sa_handler = &ft_print_signal;
	while (1)
	{
		if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
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