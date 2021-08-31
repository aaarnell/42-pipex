#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	l;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	l = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	buf = (char *)malloc(sizeof(char) * l);
	if (buf)
	{
		ft_memset(buf, '\0', l);
		ft_strlcat(buf, s1, l);
		ft_strlcat(buf, s2, l);
		return (buf);
	}
	return (NULL);
}
