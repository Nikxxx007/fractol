#include "../includes/fractol.h"

//int 	julia(t_vars *vars)
//{
//	return(0);
//}

uint32_t		fractol_degr(t_vars *vars, int i, unsigned int select)
{
	uint8_t		rgb[3];

	rgb[0] = vars->color[vars->select[select]][0];
	rgb[1] = vars->color[vars->select[select]][1];
	rgb[2] = vars->color[vars->select[select]][2];
	return ((rgb[0] * i / vars->iter) * 256 * 256 +
			(rgb[1] * i / vars->iter) * 256 +
			(rgb[2] * i / vars->iter));
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} //my_mlx_pixel_put(&vars, 5, 5, 0x00FF0000);

uint32_t fract_calculation(t_vars *vars, int x, int y)
{
	long double mx;
	long double my;
	long double c_x;
	long double c_y;
	long double x_temp;
	int 	i;

	i = 0;

	mx = 0.0;
	my = 0.0;
//	c_re = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
//	c_x = vars->min_x + (vars->max_x - vars->min_x) * (x / WIN_W);
//	c_im = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
//	c_y = vars->min_y + (vars->max_y - vars->min_y) * (y / WIN_H);

	c_x = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x - 0.75;
	c_y = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
	while (mx * mx + my * my <= 4 && i < vars->iter)
	{
		x_temp = mx * mx - my * my;
		my = 2 * mx * my + c_y;
		mx = x_temp + c_x;
		i++;
	}
//	if (i == vars->iter)
//		return (fractol_degr(vars, i, 0));
//	else if (i > vars->iter / 4)
//		return (fractol_degr(vars, i, 1));
//	else
//		return (fractol_degr(vars, i, 2));
	if (i % 4 == 0)
		return (0x00000000);
	else if (i % 4 == 1)
		return (0x00FF0000);
	else if (i % 4 == 2)
		return (0x0000FF00);
	else
		return (0x000000FF);

}

int		mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	double wheel;

	wheel = 0;
//	printf("   %d %d   ", x, y);
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
		vars->pos_x = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x;
		vars->pos_y = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
//		vars->pos_x = (float)x;
//		vars->pos_y = (float)y;
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_clear_window(vars->mlx, vars->win);
		expose_hook(vars);
	}
//	each_pixel(fractol, fractol->fractal[fractol->fnb]);
	return (1);
}

int	mandelbrot(t_vars *vars)
{
	int	x;
	int y;
	unsigned int	color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
//			printf("   %d %d   ", x, y);

			color = fract_calculation(vars, x, y);
			my_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}

	return(0);
}

int expose_hook(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
								 &vars->endian);

	//TODO func to render fract
	//TODO add user interface

	if (vars->name == 'm')
		mandelbrot(vars);
//	if (vars->name == 'j')
//		julia(vars);

	mlx_do_sync(vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

//	text for user can be added here
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(int keycode, t_vars vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return(0);
}

void win_manager(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fractol");

	mlx_hook(vars->win, 12, 0, expose_hook, vars);
//	expose_hook(vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, exit_hook,vars);


	mlx_mouse_hook(vars->win, mouse_hook, vars); //TODO add zoom in and out function

	mlx_loop(vars->mlx);
}

void v_fill(t_vars *vars)
{
	vars->name = 'n';
	vars->iter = 250;
	vars->zoom = 0.5;

	vars->pos_x = 0;
	vars->pos_y = 0;
//	vars->min_x = -1.5f;
//	vars->max_x = 1.0f;
//	vars->min_y = -1.0f;
//	vars->max_y = 1.0f;
//	vars->infinity = 10;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc == 1)
	{
		printf("KEK"); //TODO displays a list of available parameters and exits properly
		exit(2);
	}
	vars = (t_vars *) malloc(sizeof(t_vars));
	v_fill(vars); //TODO add param for julia fractal (jul_val)
	if (ft_strncmp(argv[1], "Julia", 5) == 0 ||
			ft_strncmp(argv[1], "julia", 5) == 0)
		vars->name = 'j';
	else if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 ||
				ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		vars->name = 'm';
	if (vars->name != 'n')
		win_manager(vars);
	else
		printf("kek2");//TODO add error message
	return (0);
}
