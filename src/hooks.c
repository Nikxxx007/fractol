#include "../includes/fractol.h"

int expose_hook(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
								   &vars->endian);
	calculation(vars);
	mlx_do_sync(vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars);
		exit(0);
	}
	return (0);
}

int	exit_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return(0);
}

int		mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	double wheel;

	wheel = 0;
	if (keycode == 5)
	{
		wheel = 1.0;
		vars->zoom *= 2.0 * wheel; //can be edited
	}
	if (keycode == 4)
	{
		wheel = -1;
		vars->zoom /= 2.0 * fabs(wheel);
	}
	if (wheel != 0)
	{
//		vars->iter += 15;
		vars->pos_x = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x;
		vars->pos_y = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_clear_window(vars->mlx, vars->win);
		expose_hook(vars);
	}
	return (1);
}

