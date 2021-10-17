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
//	float				infinity;
//	int					iteration;
//	long double			min_x;
	float			pos_x;
	float 			pos_y;

	int 		select[3];
	uint8_t 	color[9][3];
//	long double			max_y;
//
//	int		r;
//	int 	g;
//	int		b;

	int		iter;
	float 	zoom;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	char 	name;
	void	*mlx;
	void	*win;

	void	*img;
}				t_vars;

int expose_hook(t_vars *vars);


#endif //FRACTOL_FRACTOL_H
