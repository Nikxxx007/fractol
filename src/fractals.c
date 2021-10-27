#include "../includes/fractol.h"

void	print_mes()
{
	printf("type: ./fractol julia/mandelbrot ");
	printf("[value1_julia] [value2_julia]\n");
}

uint32_t	julia(t_vars *vars, int x, int y)
{
	long double	mx; //TODO less variobles and lines
	long double	my;
	long double	c_x;
	long double	c_y;
	long double	x_temp;
	int			i;
	int			color;

	i = 0;
	mx = 0;
	my = 0;
	color = 0x00000000;
	c_x = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x;
	c_y = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
	while (mx * mx + my * my <= 4 && i < vars->iter)
	{
		if (i != 0)
		{
			c_x = vars->jul_x;
			c_y = vars->jul_y;
		}
		x_temp = mx * mx - my * my;
		my = 2 * mx * my + c_y;
		mx = x_temp + c_x;
		color += 0x00010F0F;
		i++;
	}
	return (color);
}

uint32_t	mandelbrot(t_vars *vars, int x, int y)
{
	long double	mx;
	long double	my;
	long double	c_x;
	long double	c_y;
	long double	x_temp;
	int			i;
	int			color;

	i = 0;
	mx = 0.0;
	my = 0.0;
	color = 0x0;
	c_x = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x - 0.75;
	c_y = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
	while (mx * mx + my * my <= 4 && i < vars->iter)
	{
		x_temp = mx * mx - my * my;
		my = 2 * mx * my + c_y;
		mx = x_temp + c_x;
		color += 0x00010F0F;
		i++;
	}
	return (color);
}
