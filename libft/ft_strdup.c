#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*memory;
	int		i;

	i = 0;
	memory = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!memory)
		return (NULL);
	while (str[i])
	{
		memory[i] = str[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
