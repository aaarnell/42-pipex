#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n && str1[k] && str2[k])
	{
		if (str1[k] != str2[k])
			return ((unsigned char)str1[k] - (unsigned char)str2[k]);
		k++;
	}
	if (k < n)
		return ((unsigned char)str1[k] - (unsigned char)str2[k]);
	return (0);
}
