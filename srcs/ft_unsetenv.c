/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:54:37 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/18 22:02:37 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		del_eenv(int ret)
{
	int		i;
	int		count;

	free(g_eenv[ret]);
	g_eenv[ret] = NULL;
	i = ret;
	count = ret + 1;
	while (g_eenv[i + 1])
	{
		g_eenv[i] = ft_strdup(g_eenv[i + 1]);
		free(g_eenv[i + 1]);
		i++;
		count++;
	}
	g_eenv = realloc_eenv(count - 1);
}

int				unset_envv(char **args)
{
	int	ret;

	if (args[1] == NULL)
	{
		ft_printf("msh: need arguments\n");
		return (1);
	}
	if ((ret = check_eenv(args[1])) != -1)
		del_eenv(ret);
	return (1);
}
