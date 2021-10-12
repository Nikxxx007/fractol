#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	size_t	i;

	i = ft_strlen(string);
	if (symbol == 0)
		return ((char *)(string + i));
	while (i > 0)
	{
		if (string[i - 1] == (char)symbol)
			return ((char *)(string + i - 1));
		i--;
	}
	return (NULL);
}
