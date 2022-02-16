/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:00:51 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 19:00:52 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	size_t	i;

	i = ft_strlen(string);
	if (symbol == 0)
		return ((char *)(string + i));
	while (i > 0)
	{
		if (string[i - 1] == (char)symbol)
			return ((char *)(string + i - 1));
		i--;
	}
	return (NULL);
}
