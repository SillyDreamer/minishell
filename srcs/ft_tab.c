/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 05:21:24 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/21 16:30:04 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_tab1(void)
{
	DIR			*fd;
	t_dirent	*ret;

	fd = opendir(".");
	while ((ret = readdir(fd)) > 0)
	{
		if (!(ret->d_name[0] == '.'))
			print_type(ret);
	}
	write(1, "\n", 1);
	closedir(fd);
}

void			ft_tab2(void)
{
	DIR			*fd;
	t_dirent	*ret;

	fd = opendir(".");
	while ((ret = readdir(fd)) > 0)
	{
		if (!(ret->d_name[0] == '.') && ret->d_type == 4)
			print_type(ret);
	}
	write(1, "\n", 1);
	closedir(fd);
}

int				check_commands2(char *line)
{
	if (ft_strstr(line, "exit"))
		return (1);
	else if (ft_strstr(line, "cd"))
		return (1);
	else if (ft_strstr(line, "pwd"))
		return (1);
	else if (ft_strstr(line, "echo"))
		return (1);
	else if (ft_strstr(line, "env"))
		return (1);
	else if (ft_strstr(line, "setenv"))
		return (1);
	else if (ft_strstr(line, "unsetenv"))
		return (1);
	else if (ft_strstr(line, "mkdir"))
		return (1);
	else if (ft_strstr(line, "rm"))
		return (1);
	else if (ft_strstr(line, "help"))
		return (1);
	return (0);
}

int				check_path(char *args, int i)
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
			if (access(ret->d_name, 1) && ft_strstr(args, ret->d_name))
				return (1);
		fd ? closedir(fd) : 0;
	}
	path[0] ? free_all(path) : 0;
	return (0);
}

void			ft_tab(char *line)
{
	if (check_commands2(line) || check_path(line, -1))
	{
		if (ft_strstr(line, "cd"))
			ft_tab2();
		else
			ft_tab1();
	}
	else
		check_path2(line, -1);
}
