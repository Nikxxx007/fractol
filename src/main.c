#include "../includes/fractol.h"

//int 	julia(t_vars *vars)
//{
//	return(0);
//}

int		mandelbrot(t_vars *vars)
{
	int	x;
	int y;
	int	color;

	y = 0;
	while (y < 1200)
	{
		x = 0;
		while (x < 800)
		{
			color =
		}
	}

	return(0);
}

int expose_hook(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, 1280, 800);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
								 &vars->endian);

	//TODO func to render fract
	//TODO add user interface

	if (vars->name == 'm')
		mandelbrot(vars);
//	if (vars->name == 'j')
//		julia(vars);

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
	vars->win = mlx_new_window(vars->mlx, 1200, 800, "fractol");

	mlx_hook(vars->win, 12, 0, expose_hook, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, exit_hook,vars);


//	mlx_mouse_hook(vars->win, func_for_mouse, vars); TODO add zoom in and out function

	mlx_loop(vars->mlx);
}

void v_fill(t_vars *vars)
{
	vars->name = 'n';
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
