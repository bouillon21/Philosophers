#include "philo.h"



// void *surveillance(void *all)
// {

// }

void	get_fork_odd()
{
}

void	*philo(void *curent_philo)
{
	t_philo	*philo;

	philo = (t_philo *)curent_philo;
	// philo->start_life = get_time();
	while(1)
	{
		get_fork(philo);
		philo_eat(philo);
		throw_fork(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void start_live_philo(t_all *all)
{
	int	i;
	pthread_t	*thread;
	pthread_t	observer;

	i = -1;
	thread = malloc(sizeof(pthread_t)* all->axioms.number_of_philosophers + 1);
	// pthread_create(&thread[i], NULL, surveillance, (void *)all);
	while (++i < all->axioms.number_of_philosophers)
		pthread_create(&thread[i], NULL, philo, (void *)&all->philo[i]);
	usleep(500000);
	// pthread_join(observer, NULL);
	pthread_mutex_destroy(&g_chat);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (init(argc, argv, &all) != -1)
		start_live_philo(&all);
	return(0);

}