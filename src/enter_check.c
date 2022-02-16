/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:03:36 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 19:03:37 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	exit_check(void)
{
	printf("incorrect values");
	exit(0);
}

void	check_emp(char *str)
{
	if (!ft_strncmp(str, "", 1))
		exit_check();
}

void	dots_check(char *str)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	if (str[0] == '.')
		exit_check();
	while (str[i])
	{
		if (str[i] == '.')
			dots++;
		i++;
	}
	if (dots > 1)
		exit_check();
}

void	check_num(char *str)
{
	int	i;

	i = 0;
	check_emp(str);
	dots_check(str);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == '-' || str[i] == '+'
				|| str[i] == '.'))
		{
			printf("incorrect values");
			exit(0);
		}
		if ((str[i] == '-' || str[i] == '+') && i != 0)
			exit_check();
		i++;
	}
}
