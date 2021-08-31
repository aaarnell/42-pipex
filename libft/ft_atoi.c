#include "libft.h"

static int	cng_var(char a, unsigned long *res, int *cnt_sin, int *emp)
{
	if (a >= '0' && a <= '9')
		*res = (*res * 10) + ((unsigned long)a - 48);
	if (a == ' ' || (a >= 9 && a <= 13))
		*emp = *emp + 1;
	if (a == '-')
	{
		*cnt_sin = *cnt_sin + 1;
		return (1);
	}
	if (a == '+')
		*cnt_sin = *cnt_sin + 1;
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	r;
	int				s;
	int				cs;
	int				e;

	r = 0;
	s = 1;
	cs = 0;
	e = 0;
	while (*str)
	{
		if ((*str != ' ' && *str != '-' && *str != '+' && (*str < 9 || *str \
		> 13) && (*str < '0' || *str > '9')) || ((r != 0 || cs != 0) && (*str \
		== ' ' || *str == '-' || *str == '+' || (*str >= 9 && *str <= 13))))
			break ;
		if (cng_var(*str, &r, &cs, &e) == 1)
			s *= (-1);
		str++;
	}
	if (r > LONG_MAX && s > 0)
		r = LONG_MAX;
	if (r - 1 > LONG_MAX && s < 0)
		r = 0;
	return ((int)r * s);
}
