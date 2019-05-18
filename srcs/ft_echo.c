/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 00:33:34 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/23 04:50:35 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		msh_dollars(char *args)
{
	int		l;
	int		i;

	i = -1;
	l = ft_strlen(args);
	while (g_eenv[++i])
	{
		if (ft_strncmp(args, g_eenv[i], l) == 0)
		{
			ft_printf("%s\n", &g_eenv[i][l + 1]);
			break ;
		}
	}
	return (1);
}

int				msh_echo(char **args)
{
	int		i;
	int		j;

	i = 0;
	while (args[++i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][0] == '$' && args[i][1])
				return (msh_dollars(&args[i][1]));
			while (args[i][j] == '"')
				j++;
			if (!(args[i][j]) && args[i][j] == '"')
				break ;
			while (args[i][j] == 32)
				j++;
			write(1, &args[i][j], 1);
			args[i][j] ? j++ : 0;
		}
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (1);
}
