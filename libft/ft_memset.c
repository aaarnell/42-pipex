#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)dst)[n - 1] = c;
		n--;
	}
	return (dst);
}
