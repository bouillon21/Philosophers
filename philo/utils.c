#include "philo.h"

void	my_usleep(long time)
{
	long	t;

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