/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:00:48 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 19:00:49 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (little[j] && i + j < len)
			{
				if (little[j] != big[i + j])
					break ;
				j++;
			}
			if (j == ft_strlen(little))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
