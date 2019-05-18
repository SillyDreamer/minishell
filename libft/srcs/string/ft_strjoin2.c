/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:36:38 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/18 19:39:34 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin2(char const *s1, char const *s2, char const *s3)
{
	char	*fresh;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	fresh = (char *)ft_memalloc(len1 + len2 + len3 + 1);
	if (!fresh)
		return (NULL);
	ft_memcpy(fresh, s1, len1);
	ft_memcpy(fresh + len1, s2, len2);
	ft_memcpy(fresh + len1 + len2, s3, len3);
	fresh[len1 + len2 + len3] = '\0';
	return (fresh);
}
