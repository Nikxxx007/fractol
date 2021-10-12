#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}
