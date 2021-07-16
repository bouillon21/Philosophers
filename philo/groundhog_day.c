#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&g_chat);
	printf("\x1b[32m%zu %d is eating\n",
		get_time() - philo->start_time, philo->philo_num + 1);
	philo->start_life = get_time();
	pthread_mutex_unlock(&g_chat);
	my_usleep(philo->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&g_chat);
	printf("%zu %d is sleeping\n",
		get_time() - philo->start_time, philo->philo_num + 1);
	pthread_mutex_unlock(&g_chat);
	my_usleep(philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&g_chat);
	printf("\x1b[35m%zu %d is thinking\n",
		get_time() - philo->start_time, philo->philo_num + 1);
	pthread_mutex_unlock(&g_chat);
}

void	get_fork(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_lock(philo->right);
		pthread_mutex_lock(&g_chat);
		printf("%zu %d has taken a right fork\n",
			get_time() - philo->start_time, philo->philo_num + 1);
		pthread_mutex_unlock(&g_chat);
		pthread_mutex_lock(&philo->left);
		pthread_mutex_lock(&g_chat);
		printf("%zu %d has taken a left fork\n",
			get_time() - philo->start_time, philo->philo_num + 1);
		pthread_mutex_unlock(&g_chat);
	}
	else
	{
		pthread_mutex_lock(&philo->left);
		pthread_mutex_lock(&g_chat);
		printf("%zu %d has taken a left fork\n",
			get_time() - philo->start_time, philo->philo_num + 1);
		pthread_mutex_unlock(&g_chat);
		pthread_mutex_lock(philo->right);
		pthread_mutex_lock(&g_chat);
		printf("%zu %d has taken a right fork\n",
			get_time() - philo->start_time, philo->philo_num + 1);
		pthread_mutex_unlock(&g_chat);
	}
}

void	throw_fork(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(&philo->left);
	}
	else
	{
		pthread_mutex_unlock(&philo->left);
		pthread_mutex_unlock(philo->right);
	}
}