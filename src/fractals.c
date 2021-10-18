#include "../includes/fractol.h"

uint32_t julia(t_vars *vars, int x, int y)
{
	long double mx;
	long double my;
	long double c_x;
	long double c_y;
	long double x_temp;
	int 	i;

	i = 0;
	mx = 0;
	my = 0;
	c_x = ((x * 3.5 / 800.0) - 1.75) / vars->zoom + vars->pos_x;
	c_y = ((y * 2.0 / 600.0) - 1) / vars->zoom + vars->pos_y;
	while (mx * mx + my * my <= 4 && i < vars->iter)
	{
		if (i != 0)
		{
//			c_x = -0.88232;
//			c_y = -0.06757;
//			c_x = 0.37933;
//			c_y = 0.20533;
			c_x = -1.42292;
			c_y = -0.00067;
		}
		x_temp = mx * mx - my * my;
		my = 2 * mx * my + c_y;
		mx = x_temp + c_x;
		i++;
	}
	if (i % 4 == 0)
		return (0x00000000);
	else if (i % 4 == 1)
		return (0x00FF0000);
	else if (i % 4 == 2)
		return (0x0000FF00);
	else
		return (0x000000FF);

}

uint32_t mandelbrot(t_vars *vars, int x, int y)
{
	long double mx;
	long double my;
	long double c_x;
	long double c_y;
	long double x_temp;
	int 	i;
	int color;

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
