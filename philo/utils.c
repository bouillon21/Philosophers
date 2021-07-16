#include "philo.h"

int	print_error(char *str)
{
	printf("%s%s\n", RED, str);
	return (-1);
}

void	ft_putnbr(long int n)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10 + '0');
	write(1, &c, 1);
}

void	my_usleep(long time)
{
	long int	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(100);
}

//расчет теккущего времени в милисек
long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

long int	ft_atoi(const char *str)
{
	int			i;
	long int	rez;

	i = 0;
	rez = 0;
	if (str)
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		while (str[i] >= 48 && str[i] <= 57)
		{
			rez = rez * 10 + (str[i] - 48);
			i++;
		}
		if (str[i] != '\0')
			return (0);
	}
	return (rez);
}
