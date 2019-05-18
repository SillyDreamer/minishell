/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:34:21 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/17 20:18:22 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int				ft_wordcounts(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			j += 1;
		while (s[i + 1] && s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			i += 1;
		i += 1;
	}
	return (j);
}

static int				ft_wordlens(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i += 1;
	while (s[i] && s[i] != '\t' && s[i] != ' ' && s[i++] != '\n')
		len += 1;
	return (len);
}

char					**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**c;

	i = 0;
	k = 0;
	if (!str ||
			!(c = (char **)malloc(sizeof(char*) * (ft_wordcounts(str) + 1))))
		return (NULL);
	while (i < ft_wordcounts(str))
	{
		if (!(c[i] = (char *)malloc(sizeof(char) * (ft_wordlens(&str[k]) + 1))))
			return (NULL);
		j = 0;
		while (str[k] == '\t' || str[k] == ' ' || str[k] == '\n')
			k += 1;
		while (str[k] && str[k] != '\t' && str[k] != ' ' && str[k] != '\n')
			c[i][j++] = str[k++];
		c[i][j] = '\0';
		i += 1;
	}
	c[i] = NULL;
	return (c);
}
