/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 03:19:04 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/23 02:58:03 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_signal(int signo)
{
	if (signo == SIGINT)
		ft_printf("\n\x1B[32m(づ｡◕‿‿◕｡)づ:  \x1B[0m");
}

void	ft_signal2(int signo)
{
	if (signo == SIGINT)
		write(1, "\n", 1);
}
