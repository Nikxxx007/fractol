/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:47:25 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/16 18:47:27 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libmlx/mlx.h"
# include "libft.h"

# include <OpenGL/gl.h>
# include <OpenGl/glu.h>
# include <GLUT/glut.h>

# define WIN_H 600
# define WIN_W 800

typedef struct s_vars
{
	double		pos_x;
	double		pos_y;
	int			iter;
	double		zoom;
	double		jul_x;
	double		jul_y;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
	int			color_diff;
	char		*addr;
	char		name;
	int			shift;
	void		*mlx;
	void		*win;
	void		*img;
}				t_vars;

int			expose_hook(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			exit_hook(int keycode, t_vars *vars);

int			calculation(t_vars *vars);
int			mouse_hook(int keycode, int x, int y, t_vars *vars);

void		print_mes(void);

void		check_num(char *str);

uint32_t	mandelbrot(t_vars *vars, int x, int y);
uint32_t	julia(t_vars *vars, int x, int y);
uint32_t	b_ships(t_vars *vars, int x, int y);

double		ft_atoi_double(const char *str);
void		img_update(t_vars *vars);

#endif //FRACTOL_FRACTOL_H
