#include "../includes/fractol.h"

int	expose_hook(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	calculation(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	key_move(int keycode, t_vars *vars)
{
	if (keycode == 126)
	{
		vars->pos_y += ((0.1 * 3.5 / 800.0) - 1.75) / (100 * vars->zoom);
		img_update(vars);
	}
	if (keycode == 125)
	{
		vars->pos_y -= ((0.1 * 3.5 / 800.0) - 1.75) / (100 * vars->zoom);
		img_update(vars);
	}
	if (keycode == 123)
	{
		vars->pos_x += ((0.1 * 3.5 / 800.0) - 1.75) / (100 * vars->zoom);
		img_update(vars);
	}
	if (keycode == 124)
	{
		vars->pos_x -= ((0.1 * 3.5 / 800.0) - 1.75) / (100 * vars->zoom);
		img_update(vars);
	}
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	key_move(keycode, vars);
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars);
		exit(0);
	}
	if (keycode == 257)
	{
		if (vars->shift % 3 == 1)
			vars->color_diff = 0x0000000F;
		else if (vars->shift % 3 == 2)
			vars->color_diff = 0x00100F00;
		else if (vars->shift % 3 == 0)
			vars->color_diff = 0x00010F0F;
		if (vars->shift >= 4)
			vars->shift = 1;
		vars->shift++;
		img_update(vars);
	}
	return (0);
}

int	exit_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	double	wheel;

	wheel = 0;
	if (keycode == 5)
	{
		wheel = 1.0;
		vars->zoom *= 2.0 * wheel;
	}
	if (keycode == 4)
	{
		wheel = -1;
		vars->zoom /= 2.0 * fabs(wheel);
	}
	if (wheel != 0)
	{
		vars->iter += 10;
		vars->pos_x = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x;
		vars->pos_y = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_clear_window(vars->mlx, vars->win);
		expose_hook(vars);
	}
	return (1);
}
