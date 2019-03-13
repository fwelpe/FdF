#include "fdf.h"

int		last_index_of(char *str, char c)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}

char	*get_name(char *path)
{
	int	i;

	i = last_index_of(path, '/');
	return (&(path[i + 1]));
}