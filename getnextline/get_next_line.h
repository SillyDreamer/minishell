/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 02:33:27 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/18 22:17:26 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../includes/minishell.h"
# include <string.h>

int						get_next_line(const int fd, char **line);

typedef struct			s_btree_gnl
{
	int					fd;
	char				*temp;
	struct s_btree_gnl	*next;
}						t_btree_gnl;

#endif
