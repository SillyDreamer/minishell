/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:46:33 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/20 03:02:14 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*parse_home(void)
{
	int		i;
	char	*s;

	i = -1;
	while (g_eenv[++i])
	{
		if (ft_strncmp(g_eenv[i], "HOME", 4) == 0)
		{
			s = ft_strsub(g_eenv[i], 5, ft_strlen(g_eenv[i]) - 5);
			return (s);
		}
	}
	return (NULL);
}

static char		*parse_oldpwd(void)
{
	int		i;
	char	*s;

	i = -1;
	while (g_eenv[++i])
	{
		if (ft_strncmp(g_eenv[i], "OLDPWD", 6) == 0)
		{
			s = ft_strsub(g_eenv[i], 7, ft_strlen(g_eenv[i]) - 7);
			return (s);
		}
	}
	return (NULL);
}

static void		help_msh_cd(char *oldpwd)
{
	char	*tmp;

	tmp = parse_home();
	chdir(tmp) == 0 ? change_pwd(oldpwd) : 0;
	free(tmp);
}

static void		msh_cd_tild(char *oldpwd, char *args)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = parse_home();
	tmp2 = ft_strsub(args, 1, ft_strlen(args) - 1);
	tmp3 = ft_strjoin(tmp, tmp2);
	chdir(tmp3) == 0 ? change_pwd(oldpwd) : 0;
	free(tmp);
	free(tmp2);
	free(tmp3);
}

int				msh_cd(char **args)
{
	char	oldpwd[1024];
	char	*tmp;

	getcwd(oldpwd, 1024);
	if (args[1] == NULL)
		help_msh_cd(oldpwd);
	else if (chdir(args[1]) == 0)
		change_pwd(oldpwd);
	else if (chdir(args[1]) != 0)
	{
		if (ft_strcmp(args[1], "-") == 0)
		{
			tmp = parse_oldpwd();
			chdir(tmp) == 0 ? change_pwd(oldpwd) : 0;
			free(tmp);
		}
		else if (ft_strncmp(args[1], "~", 1) == 0)
			msh_cd_tild(oldpwd, args[1]);
		else
		{
			if (!(check_errors(args)))
				CD_ERNOTDIR(args[1], 1);
		}
	}
	return (1);
}
