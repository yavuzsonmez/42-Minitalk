/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:12 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/20 12:00:23 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char *argv[])
{
	pid_t process_id;
	char *str;

	if (argc != 3)
		return (-1);
	process_id = ft_atoi(argv[1]);
	if (process_id <= 0)
		return (-1);
	str = argv[2];
	//kill(process_id, )

	return 0;
}