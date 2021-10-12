#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
		size--;
	result = (char *)malloc(sizeof(char) * (size + 2));
	if (!result)
		return (NULL);
	while (i <= size)
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	result[i] = '\0';
	return (result);
}
