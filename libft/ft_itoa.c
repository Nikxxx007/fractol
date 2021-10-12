#include "libft.h"

size_t	counter_str(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = counter_str(n);
	string = (char *) malloc(sizeof(char) * (count + 1));
	if (!string)
		return (NULL);
	string[count--] = '\0';
	if (n == 0)
		string[0] = '0';
	if (n < 0)
	{
		string[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		string[count] = n % 10 + '0';
		n /= 10;
		count--;
	}
	return (string);
}
