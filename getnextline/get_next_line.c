/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 02:27:20 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/17 21:51:09 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_btree_gnl	*btree_create(int fd)
{
	t_btree_gnl	*c;

	c = (t_btree_gnl*)malloc(sizeof(t_btree_gnl));
	if (c)
	{
		c->fd = fd;
		c->temp = ft_strnew(BUFF_SIZE + 1);
		if (read(fd, c->temp, BUFF_SIZE) == -1)
			return (NULL);
		c->next = NULL;
	}
	return (c);
}

static t_btree_gnl	*return_btree(int fd, t_btree_gnl *begin)
{
	t_btree_gnl	*c;

	while (begin)
	{
		if (begin->fd == fd)
			return (begin);
		if (!(begin->next))
			break ;
		begin = begin->next;
	}
	if (!(c = btree_create(fd)))
		return (NULL);
	begin->next = c;
	return (c);
}

static void			copy_line(t_btree_gnl *c, char **line, char *pos)
{
	char	*s;
	char	*s2;
	char	*temp_to_free;

	s = ft_strsub(c->temp, 0, ft_strlen(c->temp) - ft_strlen(pos));
	s2 = ft_strsub(pos, 1, ft_strlen(pos) - 1);
	temp_to_free = *line;
	*line = ft_strjoin(*line, s);
	ft_memdel((void **)&temp_to_free);
	ft_memdel((void **)&s);
	ft_memdel((void **)&(c->temp));
	c->temp = s2;
}

static int			read_line(int fd, t_btree_gnl *c, char **line)
{
	char		*pos;
	int			size;
	int			len;
	char		*temp_to_free;

	size = 1;
	while (size > 0)
	{
		if ((pos = ft_strchr(c->temp, '\n')))
		{
			copy_line(c, line, pos);
			return (1);
		}
		temp_to_free = *line;
		*line = ft_strjoin(*line, c->temp);
		ft_memdel((void **)&temp_to_free);
		len = ft_strlen(c->temp);
		ft_memdel((void **)&(c->temp));
		if (!(c->temp = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		size = read(fd, c->temp, BUFF_SIZE);
		if (!len && !size)
			return (0);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	int					ret;
	static t_btree_gnl	*begin;
	t_btree_gnl			*cc;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!begin)
	{
		if (!(begin = btree_create(fd)))
			return (-1);
	}
	*line = ft_strnew(1);
	if (!(cc = return_btree(fd, begin)))
		return (-1);
	ret = read_line(fd, cc, line);
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	else
		return (-1);
}
