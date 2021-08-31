#include "libft.h"

int	ft_frmtrx(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (--i + 1)
		free(str[i]);
	free(str);
	return (0);
}
