/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:12 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/23 11:50:06 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
ft_chartobinary(char c)
{

}


void ft_encode(char *str)
{

}
*/

int main(int argc, char *argv[])
{
	pid_t	process_id;
	size_t	i;
	size_t	bits;

	if (argc != 3)
	{
		ft_putendl_fd("ERROR", 1);
		ft_putendl_fd("./client [server_pid] [string]", 1);
		return (0);
	}
	process_id = ft_atoi(argv[1]);
	i = 0;
	ft_putnbr_fd((unsigned char)argv[2][0], 1);
	ft_putchar_fd('\n', 1);
	while (argv[2][i] != '\0')
	{
		bits = 8;
		while (bits != 0)
		{
			bits--;
			if (((unsigned char)argv[2][i] >> bits & 1) == 1)
				kill(process_id, SIGUSR1);
			else if (((unsigned char)argv[2][i] >> bits & 1) == 0)
				kill(process_id, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Sending signal to : ", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putendl_fd(" ...", 1);
	kill(process_id, SIGUSR2);


	return 0;
}