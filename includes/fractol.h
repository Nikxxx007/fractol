#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libmlx/mlx.h"
# include "libft.h"

#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

typedef struct s_vars
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	char 	name;
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;


#endif //FRACTOL_FRACTOL_H
