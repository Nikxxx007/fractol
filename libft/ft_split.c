#include "libft.h"

void	memory_clean(char **new_str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
}

void	add_letters(char *string, int len, int pos, const char *source)
{
	string[len] = '\0';
	len--;
	pos--;
	while (len >= 0)
	{
		string[len] = source[pos];
		pos--;
		len--;
	}
}

void 	add_words(char const *str, char symb, char **new_str)
{
	size_t	c_i_j[3];

	c_i_j[0] = 0;
	c_i_j[1] = 0;
	c_i_j[2] = 0;
	while (c_i_j[1] < ft_strlen(str))
	{
		while (str[c_i_j[1]] != symb && str[c_i_j[1]])
		{
			c_i_j[1]++;
			c_i_j[0]++;
		}
		if (c_i_j[0] > 0)
		{
			new_str[c_i_j[2]] = (char *)malloc(sizeof(char) * c_i_j[0] + 1);
			if (!new_str[c_i_j[2]])
				return (memory_clean(new_str, c_i_j[2]));
			add_letters(new_str[c_i_j[2]++], c_i_j[0], c_i_j[1], str);
		}
		c_i_j[0] = 0;
		c_i_j[1]++;
	}
	new_str[c_i_j[2]] = 0;
}

int	words_amount(char const *str, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && ((str[i + 1] == c) || str[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;

	if (!s)
		return (NULL);
	new_str = (char **) malloc(sizeof(char *) * (words_amount(s, c) + 1));
	if (!new_str)
		return (NULL);
	add_words(s, c, new_str);
	return (new_str);
}
