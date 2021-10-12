#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*changed;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	changed = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!changed)
		return (NULL);
	while (s[i])
	{
		changed[i] = f(i, s[i]);
		i++;
	}
	changed[i] = '\0';
	return (changed);
}
