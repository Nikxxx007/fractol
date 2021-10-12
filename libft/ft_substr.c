#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*memory;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	memory = (char *)malloc(sizeof(char) * (len + 1));
	if (!memory)
		return (NULL);
	while (i < len && s[start] && start < ft_strlen(s))
	{
		memory[i] = s[start];
		start++;
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
