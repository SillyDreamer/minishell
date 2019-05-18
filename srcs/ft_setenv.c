/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:48:13 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/18 23:26:48 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_eenv(int i, char *name, char *value)
{
	char	*s;

	free(g_eenv[i]);
	if (value != NULL)
		s = ft_strjoin2(name, "=", value);
	else
		s = ft_strjoin(name, "=");
	g_eenv[i] = ft_strdup(s);
	free(s);
}

char	**realloc_eenv(int new_size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size + 1));
	i = -1;
	while (g_eenv[++i] && i < new_size)
	{
		new[i] = ft_strdup(g_eenv[i]);
		free(g_eenv[i]);
	}
	free(g_eenv);
	return (new);
}

void	add_eenv(char *name, char *value)
{
	char	*s;
	int		l;
	int		i;

	i = 0;
	l = strlen_geenv();
	if (value != NULL)
		s = ft_strjoin2(name, "=", value);
	else
		s = ft_strjoin(name, "=");
	g_eenv = realloc_eenv(l + 1);
	g_eenv[l] = ft_strdup(s);
	free(s);
}

int		set_env(char **args)
{
	int		i;
	int		ret;

	i = -1;
	if (args[1] == NULL)
	{
		print_eenv();
		return (1);
	}
	if ((ret = check_eenv(args[1])) != -1)
		change_eenv(ret, args[1], args[2]);
	else
		add_eenv(args[1], args[2]);
	return (1);
}
