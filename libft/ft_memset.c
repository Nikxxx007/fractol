#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)destination;
	i = 0;
	while (i < n)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return (destination);
}
