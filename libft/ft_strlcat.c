#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	k;
	size_t	p;

	i = ft_strlen(dst);
	if (n <= i)
		return (ft_strlen((char *)src) + n);
	k = ft_strlen((char *)src);
	p = 0;
	while (p < k && p < n - i - 1)
	{
		dst[i + p] = src[p];
		p++;
	}
	dst[i + p] = '\0';
	return (ft_strlen((char *)src) + i);
}
