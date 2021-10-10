/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:54:40 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:54:41 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	size_m;

	size_m = ft_strlen(s1);
	ptr = (char *)malloc(size_m + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size_m)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
