/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:48:16 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/21 16:15:31 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				check_commands3(char *line)
{
	if (ft_strncmp("exit", line, ft_strlen(line) - 1) == 0)
		PRINT("exit\n", 1);
	else if (ft_strncmp(line, "cd", ft_strlen(line) - 1) == 0)
		PRINT("cd\n", 1);
	else if (ft_strncmp(line, "pwd", ft_strlen(line) - 1) == 0)
		PRINT("pwd\n", 1);
	else if (ft_strncmp(line, "echo", ft_strlen(line) - 1) == 0)
		PRINT("echo\n", 1);
	else if (ft_strncmp(line, "env", ft_strlen(line) - 1) == 0)
		PRINT("env\n", 1);
	else if (ft_strncmp(line, "setenv", ft_strlen(line) - 1) == 0)
		PRINT("seteenv\n", 1);
	else if (ft_strncmp(line, "unsetenv", ft_strlen(line) - 1) == 0)
		PRINT("unsetenv\n", 1);
	else if (ft_strncmp(line, "mkdir", ft_strlen(line) - 1) == 0)
		PRINT("mkdir\n", 1);
	else if (ft_strncmp(line, "rm", ft_strlen(line) - 1) == 0)
		PRINT("rm\n", 1);
	else if (ft_strncmp(line, "help", ft_strlen(line) - 1) == 0)
		PRINT("help\n", 1);
	return (0);
}

int				check_path2(char *args, int i)
{
	char		**path;
	DIR			*fd;
	t_dirent	*ret;
	int			l;

	if ((l = check_eenv("PATH")) == -1)
		return (0);
	path = ft_strsplit(&g_eenv[l][5], ':');
	while ((path[++i]))
	{
		fd = opendir(path[i]);
		while ((ret = readdir(fd)))
		{
			if (ft_strncmp(ret->d_name, args, ft_strlen(args) - 1) == 0)
				ft_printf("%s   ", ret->d_name);
		}
		fd ? closedir(fd) : 0;
	}
	ft_printf("\n");
	path[0] ? free_all(path) : 0;
	return (0);
}
