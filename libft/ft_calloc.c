#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(count * size);
	if (r)
	{
		ft_memset(r, '\0', count * size);
		return (r);
	}
	return (NULL);
}
