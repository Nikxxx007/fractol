#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr_s;
	size_t			i;

	arr = (unsigned char *)destination;
	arr_s = (unsigned char *)source;
	i = 0;
	if (!n || destination == source)
		return (destination);
	while (i < n)
	{
		arr[i] = arr_s[i];
		i++;
	}
	return (destination);
}
