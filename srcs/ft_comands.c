/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:35:21 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/21 13:10:49 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_exit(void)
{
	exit(0);
}

int		msh_pwd(char **args)
{
	char path[1024];

	if (!(getcwd(path, 1024)))
	{
		perror("msh");
		ft_printf("\n");
	}
	else if (args[1] != NULL)
		ft_printf("msh: pwd: too many arguments\n");
	else
		ft_printf("%s\n", path);
	return (1);
}

int		check_commands(char **s)
{
	if (ft_strequ(s[0], "exit"))
		return (msh_exit());
	else if (ft_strequ(s[0], "cd"))
		return (msh_cd(s));
	else if (ft_strequ(s[0], "pwd"))
		return (msh_pwd(s));
	else if (ft_strequ(s[0], "echo"))
		return (msh_echo(s));
	else if (ft_strequ(s[0], "env"))
		return (print_eenv());
	else if (ft_strequ(s[0], "setenv"))
		return (set_env(s));
	else if (ft_strequ(s[0], "unsetenv"))
		return (unset_envv(s));
	else if (ft_strequ(s[0], "mkdir"))
		return (make_dir(s[1]));
	else if (ft_strequ(s[0], "rm"))
		return (remove_dir(s[1]));
	else if (ft_strequ(s[0], "help"))
		return (help());
	return (0);
}

int		msh_comands(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = -1;
	ret = 0;
	while (commands[++i])
	{
		command = ft_split_whitespaces(commands[i]);
		msh_execute(command);
		free_all(command);
	}
	return (ret);
}
