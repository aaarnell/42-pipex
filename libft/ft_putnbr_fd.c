#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	k;

	k = (unsigned int) n;
	if (n < 0)
	{
		ft_putchar_fd(45, fd);
		k = (unsigned int) n * (-1);
	}
	if (k >= 10)
		ft_putnbr_fd((k / 10), fd);
	ft_putchar_fd((k % 10 + 48), fd);
}
