#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*arr;
	unsigned char	*arr_s;
	size_t			i;

	arr = (unsigned char *)buf1;
	arr_s = (unsigned char *)buf2;
	i = 0;
	while (i < count)
	{
		if (arr[i] != arr_s[i])
			return ((int)(arr[i] - arr_s[i]));
		i++;
	}
	return (0);
}
