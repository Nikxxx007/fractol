#include "libft.h"

int	ft_isalnum(int ch)
{
	if (((ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z')) || (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}
