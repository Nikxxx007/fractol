#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)symbol)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == symbol)
		return ((char *)(string + i));
	return (NULL);
}
