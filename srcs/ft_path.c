/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 03:15:14 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/23 00:57:06 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*parse_path(char *args, int i)
{
	char		**path;
	DIR			*fd;
	t_dirent	*ret;
	char		*bin_path;
	int			l;

	if ((l = check_eenv("PATH")) == -1)
		return (NULL);
	path = ft_strsplit(&g_eenv[l][5], ':');
	while ((path[++i]))
	{
		fd = opendir(path[i]);
		while ((ret = readdir(fd)))
			if (access(ret->d_name, 1) && ft_strequ(ret->d_name, args))
			{
				bin_path = ft_strjoin2(path[i], "/", args);
				closedir(fd);
				free_all(path);
				return (bin_path);
			}
		fd ? closedir(fd) : 0;
	}
	path[0] ? free_all(path) : 0;
	return (NULL);
}
