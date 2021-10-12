#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char    *result;
    size_t    s1_len;
    size_t    s2_len;

    if (!s1 && !s2)
        return (0);
    s1_len = ft_strlen((char *)s1);
    s2_len = ft_strlen((char *)s2);
    result = malloc(sizeof(char) * (s1_len + s2_len) + 1);
    if (!result)
        return (0);
    ft_memmove(result, s1, s1_len);
    ft_memmove(result + s1_len, s2, s2_len);
    result [s1_len + s2_len] = '\0';
    return (result);
}
