/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:58:06 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 18:58:08 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if (((ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z')) || (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}
