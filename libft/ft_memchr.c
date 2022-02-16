/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:59:10 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 18:59:11 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*copy;
	size_t			i;

	copy = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (copy[i] == (const unsigned char)c)
			return (copy + i);
		i++;
	}
	return (NULL);
}
