#include "../includes/fractol.h"

int	check_sign(const char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	else
		return (1);
}

double	ft_atoi_double(const char *str)
{
	double	new[2];
	double	m_d_c[3];

	new[0] = 0;
	new[1] = 0;
	m_d_c[1] = 0;
	m_d_c[0] = check_sign(&str);
	while ((*str >= '0' && *str <= '9') || *str == '.')
	{
		if (*str == '.')
		{
			m_d_c[1] = 1.0;
			str++;
		}
		if (m_d_c[1] == 1.0)
		{
			new[1] = (new[1] * 10) + (*str - '0');
			m_d_c[2]++;
		}
		else
			new[0] = (new[0] * 10) + (*str - '0');
		str++;
	}
	return ((new[0] + (new[1] * pow(0.1, m_d_c[2]))) * m_d_c[0]);
}
