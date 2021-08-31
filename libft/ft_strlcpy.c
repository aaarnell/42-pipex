#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{	
	size_t	i;
	size_t	k;

	if (!dst || !src)
		return (0);
	i = 0;
	k = ft_strlen((char *)src);
	if (dstsize == 0)
		return (k);
	while (i < dstsize - 1 && i < k)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (k);
}
