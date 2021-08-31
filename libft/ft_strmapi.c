#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;
	size_t			k;

	if (s == NULL)
		return (NULL);
	k = ft_strlen((char *)s);
	r = (char *)malloc(sizeof(char) * (k + 1));
	if (r == NULL)
		return (NULL);
	ft_bzero(r, k);
	i = 0;
	while (s[i])
	{
		r[i] = (*f)(i, s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
