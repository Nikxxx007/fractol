#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*memory;

	memory = malloc(num * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, num * size);
	return (memory);
}
