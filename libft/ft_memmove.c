/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:59:20 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 18:59:21 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	unsigned char	*arr;
	unsigned char	*arr_s;
	size_t			i;

	arr = (unsigned char *)destptr;
	arr_s = (unsigned char *)srcptr;
	i = 0;
	if (!num || destptr == srcptr)
		return (destptr);
	if (srcptr < destptr)
	{
		i = num;
		while (i > 0)
		{
			arr[i - 1] = arr_s[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(destptr, srcptr, num);
	return (destptr);
}
