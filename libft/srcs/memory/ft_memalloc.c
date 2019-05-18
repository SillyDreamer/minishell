/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:07:29 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/02/18 20:07:16 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory_ft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = malloc(size);
	if (!fresh)
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
