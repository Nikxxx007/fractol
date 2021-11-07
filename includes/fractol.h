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
	double 			pos_x;
	double 			pos_y;
	int		iter;
	double 	zoom;

	double	jul_x;
	double	jul_y;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	char 	name;
	void	*mlx;
	void	*win;

	void	*img;
}				t_vars;

int			expose_hook(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			exit_hook(int keycode, t_vars *vars);

int			calculation(t_vars *vars);
int			mouse_hook(int keycode, int x, int y, t_vars *vars);

uint32_t	mandelbrot(t_vars *vars, int x, int y);
uint32_t	julia(t_vars *vars, int x, int y);

double		ft_atoi_double(const char *str);


#endif //FRACTOL_FRACTOL_H
