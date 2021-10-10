/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:54:15 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:54:15 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *des, int c, size_t n)
{
	size_t			i;
	unsigned char	*g;
	char			v;

	i = 0;
	g = (unsigned char *)des;
	v = (unsigned char)c;
	while (i < n)
	{
		g[i] = v;
		i++;
	}
	return (des);
}
