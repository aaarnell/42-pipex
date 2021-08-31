#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	len;

	len = sizeof(char) * ft_strlen((char *)s1) + 1;
	buf = (char *)malloc(len);
	if (buf)
	{
		ft_strlcpy(buf, s1, len);
		return (buf);
	}
	return (NULL);
}
