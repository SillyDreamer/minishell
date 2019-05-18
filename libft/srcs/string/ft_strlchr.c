/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:45:42 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/17 20:18:08 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strlchr(char *s, int c)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			k++;
		i++;
	}
	return (k);
}
