/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:03:51 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 19:03:52 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_update(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	calculation(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
