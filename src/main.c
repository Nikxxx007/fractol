#include "../includes/fractol.h"

int rend_pic(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, 1280, 800);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
								 &vars->endian);

	//TODO func to render fract
	//TODO add user interface

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

	return (0);
}

int	key_pressed_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void win_manager(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1200, 800, "fractol");

	mlx_expose_hook(vars->win, rend_pic, vars);
	mlx_hook(vars->win, 2, 0, key_pressed_hook, vars);

//	mlx_mouse_hook(vars->win, func_for_mouse, vars);

	mlx_loop(vars->mlx);
}

void v_fill(t_vars *vars)
{
	vars->name = 'n';
}

int	main(int argc, char **argv)
{
//	t_vars	vars;
//
//	vars.mlx = mlx_init();
//	vars.win = mlx_new_window(vars.mlx, 1280, 800, "Hello world!");
//	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_loop(vars.mlx);
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

//	mlx = mlx_init();
//	vars.win = mlx_new_window(mlx, 720, 480, "Hello world!");
//	img.img = mlx_new_image(mlx, 720, 480);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								 &img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

//	mlx_loop_hook(mlx, render_next_frame, YourStruct);
}
