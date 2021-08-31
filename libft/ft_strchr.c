#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	size_t	t;

	i = ft_strlen((char *)str);
	t = 0;
	while (t <= i)
	{
		if (str[t] == (char)ch)
			return ((char *)(str + t));
		t++;
	}
	return (NULL);
}
