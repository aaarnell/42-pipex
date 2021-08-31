#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	t;

	t = 0;
	while (t < n)
	{
		((unsigned char *)dst)[t] = ((unsigned char *)src)[t];
		if (((unsigned char *)src)[t++] == (unsigned char)c)
			return (dst + t);
	}
	return (NULL);
}
