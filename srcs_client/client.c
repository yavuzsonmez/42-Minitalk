/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:12 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/20 19:23:25 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int main(int argc, char *argv[])
{
	pid_t	process_id;
	char	*str;
	//size_t	i;
	//size_t	bits;


	process_id = ft_atoi(argv[1]);
	if (argc != 3 && process_id <= 0)
	{
		ft_putstr_fd("ERROR\n", 1);
		return (-1);
	}
	str = argv[2];
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
	kill(process_id, SIGUSR1);

	return 0;
}