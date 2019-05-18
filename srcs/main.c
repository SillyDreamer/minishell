/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:20:34 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/23 04:51:01 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		msh_launch(char **args, char *path)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, ft_signal2);
	if (pid == 0)
	{
		if (execve(path, args, g_eenv) == -1)
		{
			ft_printf("msh: Command not found: %s\n", path);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		ft_printf("msh: errors at forking");
	else if (pid > 0)
		wait(&pid);
	return (1);
}

int				msh_execute(char **args)
{
	char	*parsed_path;

	if (args[0] == NULL)
		return (1);
	parsed_path = parse_path(args[0], -1);
	if (!(check_commands(args)))
	{
		if (parsed_path != NULL)
		{
			msh_launch(args, parsed_path);
			free(parsed_path);
			return (1);
		}
		else
			return (access(args[0], 1) ?
			ft_printf("msh: Command not found: %s\n",
			args[0]) : msh_launch(args, args[0]));
	}
	free(parsed_path);
	return (1);
}

static void		msh_loop(void)
{
	char	**args;
	int		i;
	int		ret;
	char	*line;

	i = -1;
	ret = 0;
	while (1)
	{
		ft_printf("\x1B[32m(づ｡◕‿‿◕｡)づ:  \x1B[0m");
		signal(SIGINT, ft_signal);
		get_next_line(0, &line);
		if (ft_strchr(line, 9))
		{
			ft_tab(line);
			continue ;
		}
		args = ft_strsplit(line, ';');
		free(line);
		ret = msh_comands(args);
		free_all(args);
		if (ret == -1)
			break ;
	}
}

int				main(int ac, char **av, char **eenv)
{
	(void)ac;
	(void)av;
	init_eenv(eenv);
	if (check_eenv("SHLVL") != -1)
		change_eenv(check_eenv("SHLVL"), "SHLVL",
		ft_itoa(ft_atoi(&g_eenv[check_eenv("SHLVL")][6]) + 1));
	else
		add_eenv("SHLVL", "1");
	msh_loop();
	return (0);
}
