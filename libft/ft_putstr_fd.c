#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	temp;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		temp = s[i];
		write(fd, &temp, 1);
		i++;
	}
}
