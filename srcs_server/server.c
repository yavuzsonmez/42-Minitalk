/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/24 20:16:33 by ysonmez          ###   ########.fr       */
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

static void	ft_print_signal(int sig, siginfo_t *info, void *context)
{
	static char		c;
	static size_t	size;

	(void)context;
	if (sig == SIGUSR2)
		sig = 0;
	else if (sig == SIGUSR1)
		sig = 1;
	if (c == 0 && size == 0)
		size = 7;
	size--;
	c += (sig & 1) << size;
	if (size == 0)
	{
		if (!c)
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(c, 1);
		size = 7;
		c = 0;
	}
	kill(SIGUSR1, info->si_pid);
}

int	main(void)
{
	struct sigaction	act;

	ft_pid();
	ft_memset (&act, '\0', sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_print_signal;
	act.sa_flags = SA_SIGINFO;

	while (1)
	{
		if (sigaction(SIGUSR1, &act, NULL) < 0
			|| sigaction(SIGUSR2, &act, NULL) < 0)
		{
			ft_putendl_fd("An error has occurred", 1);
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return (0);
}
