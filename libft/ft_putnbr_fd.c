#include "libft.h"

void	helper(int nb, int fd)
{
	int	digit;

	if (nb != 0)
	{
		digit = (nb % 10) + '0';
		helper(nb / 10, fd);
		write(fd, &digit, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		helper(n, fd);
	}
}
