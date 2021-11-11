#include "../includes/fractol.h"

void	img_update(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	calculation(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
