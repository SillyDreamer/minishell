/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:32:05 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/21 14:29:06 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		strlen_geenv(void)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (g_eenv[++i])
		count++;
	return (count);
}

int		check_errors(char **args)
{
	(!(access(args[1], F_OK) == -1)) ? 0 : CD_ERNOTEXIST(args[1], 1);
	(!(access(args[1], R_OK) == -1)) ? 0 : CD_ERPERM(args[1], 1);
	return (0);
}

void	free_all(char **mas)
{
	int		i;

	i = -1;
	while (mas[++i])
		free(mas[i]);
	free(mas);
}

void	change_pwd(char *oldpwd)
{
	char	path[1024];
	int		k;

	getcwd(path, 1024);
	(k = check_eenv("PWD")) == -1 ? add_eenv("PWD", path) :
	change_eenv(k, "PWD", path);
	(k = check_eenv("OLDPWD")) == -1 ? add_eenv("OLDPWD", path) :
	change_eenv(k, "OLDPWD", oldpwd);
}

void	print_type(t_dirent *ret)
{
	ret->d_type == 4 ? ft_printf(BLU "%s  " NRM, ret->d_name) : 0;
	ret->d_type == 10 ? ft_printf(MAG "%s   " NRM, ret->d_name) : 0;
	ret->d_type == 2 ? ft_printf(YEL "%s  " NRM, ret->d_name) : 0;
	ret->d_type == 6 ? ft_printf(GRN "%s   " NRM, ret->d_name) : 0;
	if (ret->d_type == 8 && (access(ret->d_name, 1)))
		ft_printf(RED "%s  " NRM, ret->d_name);
	else if (ret->d_type == 8)
		ft_printf("%s ", ret->d_name);
}
