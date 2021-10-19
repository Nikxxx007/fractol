#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, unsigned int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	calculation(t_vars *vars)
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
			if (vars->name == 'm')
				color = mandelbrot(vars, x, y);
			if (vars->name == 'j')
				color = julia(vars, x, y);
			my_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
	return(0);
}

void win_manager(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fractol");
	mlx_hook(vars->win, 12, 0, expose_hook, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, exit_hook,vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars); //TODO add zoom in and out function
	mlx_loop(vars->mlx);
}

void v_fill(t_vars *vars, char **args)
{
	vars->name = 'n';
	vars->iter = 1000;
	vars->zoom = 0.5;
	vars->pos_x = 0;
	vars->pos_y = 0;
	if (args[2] && args[3])
	{
		vars->jul_x = ft_atoi_double(args[2]); //TODO remake atoi() for double
		vars->jul_y = ft_atoi_double(args[3]);
	}
	else
	{
		vars->jul_x = -0.88232;
		vars->jul_y = -0.06757;
	}
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc == 1)
	{
		printf("type: ./fractol julia/mandelbrot [value1_julia] [value2_julia]\n");
		exit(2);
	}
	vars = (t_vars *) malloc(sizeof(t_vars));
	v_fill(vars, argv); //TODO add param for julia fractal (jul_val)
	if (ft_strncmp(argv[1], "Julia", 5) == 0 ||
			ft_strncmp(argv[1], "julia", 5) == 0)
		vars->name = 'j';
	else if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 ||
				ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		vars->name = 'm';
	if (vars->name != 'n')
		win_manager(vars);
	else
	{
		free(vars);
		printf("type: ./fractol julia/mandelbrot [value1_julia] [value2_julia]\n");
	}
	return (0);
}
