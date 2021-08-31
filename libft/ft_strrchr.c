#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int				i;
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (tmp[i] == (unsigned char)ch)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
