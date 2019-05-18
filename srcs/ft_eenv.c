/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 04:36:39 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/18 22:02:26 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		strlen_eenv(char **eenv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (eenv[++i])
		count++;
	return (count);
}

void			init_eenv(char **eenv)
{
	int		i;

	g_eenv = (char **)malloc(sizeof(char *) * (strlen_eenv(eenv) + 1));
	i = -1;
	while (eenv[++i])
	{
		if (!(g_eenv[i] = ft_strdup(eenv[i])))
			msh_exit();
	}
	g_eenv[i] = NULL;
}

int				print_eenv(void)
{
	int		i;
	int		j;

	i = 0;
	j = strlen_geenv();
	while (i < j)
	{
		ft_printf("%s\n", g_eenv[i]);
		i++;
	}
	return (1);
}

int				check_eenv(char *name)
{
	int		i;
	int		l;

	i = -1;
	l = 0;
	while (g_eenv[++i])
	{
		if (ft_strncmp(name, g_eenv[i], ft_strlen(name)) == 0)
			return (i);
	}
	return (-1);
}
