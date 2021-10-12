#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr_s;
	size_t			i;

	arr = (unsigned char *)destination;
	arr_s = (unsigned char *)source;
	i = 0;
	while (i < n)
	{
		arr[i] = arr_s[i];
		if (arr_s[i] == (unsigned char)c)
			return (arr + i + 1);
		i++;
	}
	return (NULL);
}
