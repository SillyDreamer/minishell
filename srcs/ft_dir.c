/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:19:49 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/18 23:31:01 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		make_dir(char *name)
{
	if (name == NULL)
	{
		ft_putstr("msh: mkdir: need more argument");
		return (1);
	}
	else
	{
		if (mkdir(name, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1)
			ft_putstr("msh: mkdir: error");
	}
	return (1);
}

int		remove_dir(char *name)
{
	if (name == NULL)
	{
		ft_putstr("msh: rm: need more argument");
		return (1);
	}
	else
	{
		if (rmdir(name) == -1)
			ft_putstr("msh: rm: error");
	}
	return (1);
}

int		help(void)
{
	ft_putstr("Msh by ghazrak-\n");
	ft_putstr("Type program names and arguments, and hit enter.\n");
	ft_putstr("The following are built in:\n");
	ft_printf("cd\necho\npwd\nmkdir\nrm\nenv\nsetenv\nunsetenv\nhelp\nexit\n");
	ft_putstr("Use the man command for information on other programs.\n");
	return (1);
}
