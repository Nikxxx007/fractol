#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	temp;

	temp = 0;
	while (str[temp])
		temp++;
	return (temp);
}
