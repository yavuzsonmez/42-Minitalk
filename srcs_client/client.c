/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:12 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/23 09:37:37 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
ft_chartobinary(char c)
{

}

ft_encode(char *str)
{

}
*/

int main(int argc, char *argv[])
{
	pid_t	process_id;
	char	*str;
	//size_t	i;
	//size_t	bits;

	if (argc != 3)
	{
		ft_putendl_fd("ERROR", 1);
		ft_putendl_fd("./client [server_pid] [string]", 1);
		return (0);
	}
	process_id = ft_atoi(argv[1]);
	str = argv[2];
	//ft_encode(str);
	//while(argv[2][i])
	//{
	//	bits = 8;
	//	while(bits & bits << 1)
	//	{
	//		if (argv[2][i] && bits << 1)
	//			kill(process_id, SIGUSR1);
	//		else
	//			kill(process_id, SIGUSR2);
//
	//	}
	//}
	ft_putstr_fd("Sending signal to : ", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putendl_fd(" ...", 1);
	kill(process_id, SIGUSR2);


	return 0;
}