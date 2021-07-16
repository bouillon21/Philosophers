#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&g_chat);
	printf("%s⏰%zu\t|%d|\t🍔is eating🍟\n", GREEN,
		get_time() - philo->start_time, philo->philo_num + 1);
	philo->start_life = get_time();
	pthread_mutex_unlock(&g_chat);
	my_usleep(philo->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&g_chat);
	printf("%s⏰%zu\t|%d|\t💤is sleeping💤\n", BLUE,
		get_time() - philo->start_time, philo->philo_num + 1);
	pthread_mutex_unlock(&g_chat);
	my_usleep(philo->time_to_sleep);
	philo_think(philo);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&g_chat);
	printf("%s⏰%zu\t|%d|\t🎻is thinking🎻\n", YELLOW,
		get_time() - philo->start_time, philo->philo_num + 1);
	pthread_mutex_unlock(&g_chat);
}

void	get_fork(t_philo *philo, t_mutex *first, t_mutex *second)
{
	pthread_mutex_lock(first);
	pthread_mutex_lock(&g_chat);
	printf("%s⏰%zu\t|%d|\t🥄has taken a fork🥄\n", WHITE,
		get_time() - philo->start_time, philo->philo_num + 1);
	pthread_mutex_unlock(&g_chat);
	pthread_mutex_lock(second);
	pthread_mutex_lock(&g_chat);
	printf("%s⏰%zu\t|%d|\t🥄has taken a fork🥄\n", WHITE,
		get_time() - philo->start_time, philo->philo_num + 1);
	pthread_mutex_unlock(&g_chat);
}

void	throw_fork(t_philo *philo, t_mutex *first, t_mutex *second)
{
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}
