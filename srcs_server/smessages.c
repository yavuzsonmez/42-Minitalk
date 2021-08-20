/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smessages.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:58:57 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/20 14:54:55 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	ft_putpid(void)
{
	ft_putstr_fd("MINITALK SERVER..\n", 1);
	ft_putstr_fd("PROCESS ID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}