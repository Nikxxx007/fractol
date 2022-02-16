/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:03:40 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 19:03:41 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_mes(void)
{
	printf("type: ./fractol julia/mandelbrot/ships ");
	printf("[value1_julia] [value2_julia]\n");
	exit(0);
}

uint32_t	julia(t_vars *vars, int x, int y)
{
	long double	mx_my[2];
	long double	cx_cy[2];
	long double	x_temp;
	int			i;

	i = 0;
	mx_my[0] = 0;
	mx_my[1] = 0;
	vars->color = 0x00000000;
	cx_cy[0] = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x;
	cx_cy[1] = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
	while (mx_my[0] * mx_my[0] + mx_my[1] * mx_my[1] <= 4 && i < vars->iter)
	{
		if (i != 0)
		{
			cx_cy[0] = vars->jul_x;
			cx_cy[1] = vars->jul_y;
		}
		x_temp = mx_my[0] * mx_my[0] - mx_my[1] * mx_my[1];
		mx_my[1] = 2 * mx_my[0] * mx_my[1] + cx_cy[1];
		mx_my[0] = x_temp + cx_cy[0];
		vars->color += vars->color_diff;
		i++;
	}
	return (vars->color);
}

uint32_t	mandelbrot(t_vars *vars, int x, int y)
{
	long double	mx_my[2];
	long double	cx_cy[2];
	long double	x_temp;
	int			i;

	i = 0;
	mx_my[0] = 0.0;
	mx_my[1] = 0.0;
	vars->color = 0x0;
	cx_cy[0] = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x - 0.75;
	cx_cy[1] = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
	while (mx_my[0] * mx_my[0] + mx_my[1] * mx_my[1] <= 4 && i < vars->iter)
	{
		x_temp = mx_my[0] * mx_my[0] - mx_my[1] * mx_my[1];
		mx_my[1] = 2 * mx_my[0] * mx_my[1] + cx_cy[1];
		mx_my[0] = x_temp + cx_cy[0];
		vars->color += vars->color_diff;
		i++;
	}
	return (vars->color);
}

uint32_t	b_ships(t_vars *vars, int x, int y)
{
	long double	mx_my[2];
	long double	cx_cy[2];
	long double	x_temp;
	int			i;

	i = 0;
	mx_my[0] = 0.0;
	mx_my[1] = 0.0;
	vars->color = 0x0;
	cx_cy[0] = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x - 0.75;
	cx_cy[1] = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
	while (mx_my[0] * mx_my[0] + mx_my[1] * mx_my[1] <= 4 && i < vars->iter)
	{
		x_temp = mx_my[0] * mx_my[0] - mx_my[1] * mx_my[1];
		mx_my[1] = fabsl(2 * mx_my[0] * mx_my[1] + cx_cy[1]);
		mx_my[0] = fabsl(x_temp + cx_cy[0]);
		if (mx_my[0] * mx_my[0] + mx_my[1] * mx_my[1] >= 4)
			break ;
		vars->color += vars->color_diff;
		i++;
	}
	return (vars->color);
}
