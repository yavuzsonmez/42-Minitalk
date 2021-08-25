/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:12 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/25 10:29:58 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

size_t sigret;

static int	ft_error(void)
{
	ft_putendl_fd("An error has occurred", 1);
	ft_putendl_fd("Make sure that server is launched: ./server", 1);
	ft_putendl_fd("Launch client: ./client [server_pid] [string]", 1);
	return (0);
}


static void ft_counter(int signum)
{
	printf("%s\n", "TEST");
	//(void)signum;
	ft_putnbr_fd(signum, 1);
	sigret++;
}


static void	ft_encode(char *str, pid_t pid)
{
	size_t	i;
	size_t	bits;

	i = 0;
	while (1)
	{
		while (str[i] != '\0')
		{
			bits = 7;
			while (bits != 0)
			{
				bits--;
				if (((unsigned char)str[i] >> bits & 1) == 1)
					kill(pid, SIGUSR1);
				else if (((unsigned char)str[i] >> bits & 1) == 0)
					kill(pid, SIGUSR2);
				usleep(100);
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	struct sigaction	act;

	ft_memset (&act, '\0', sizeof(act));
	act.sa_handler = ft_counter;

	if (argc != 3 && !ft_error())
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid < 1 && !ft_error())
		return (-1);
	/*TEST*/
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	/*END TEST*/
	ft_putstr_fd("Sending data to : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putendl_fd("..", 1);
	while(1)
	{
		if (sigret == 0)
			ft_encode(argv[2], pid);
		if (sigaction(SIGUSR1, &act, NULL) < 0)
		{
			ft_putendl_fd("An error has occurred", 1);
			exit(EXIT_FAILURE);
		}
		if (sigret == 7)
			exit(EXIT_SUCCESS);
		pause();
	}
	return (0);
}
