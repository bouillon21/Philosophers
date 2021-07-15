#include "philo.h"

void init_philo(t_all *all)
{
	int	i;

	i = -1;
	all->philo = malloc(sizeof(t_philo *)* all->axioms.number_of_philosophers + 1);
	while(++i < all->axioms.number_of_philosophers)
	{
		pthread_mutex_init(&all->philo[i].left, NULL);
		all->philo[i].philo_num = i;
		all->philo[i].time_to_eat = all->axioms.time_to_eat;
		all->philo[i].time_to_sleep = all->axioms.time_to_sleep;
		all->philo[i].time_to_die = all->axioms.time_to_die;
		all->philo[i].number_meals = all->axioms.number_meals;
		all->philo[i].start_time = all->start_time;
		all->philo[i].start_life = all->start_time;
	}
	all->philo[i - 1].right = &all->philo[0].left;
	i = -1;
	while (++i < all->axioms.number_of_philosophers - 1)
		all->philo[i].right = &all->philo[i].left;
}

int init(int argc, char **argv, t_all *all)
{
	if (check_args(argc, argv, all))
		return(-1);
	pthread_mutex_init(&g_chat, NULL);
	init_philo(all);
	return (0);
}

void *surveillance(void *curent_philo)
{
	
}

void start_live_philo(t_all *all)
{
	int	i;
	pthread_t	*thread;
	pthread_t	observer;

	i = -1;
	all->start_time = get_time();
	thread = malloc(sizeof(pthread_t)* all->axioms.number_of_philosophers + 1);
	while (++i < all->axioms.number_of_philosophers)
		pthread_create(&thread[i], NULL, surveillance, (void *)&all->philo[i]);
	pthread_join(observer, NULL);
	pthread_mutex_destroy(&g_chat);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (init(argc, argv, &all) != -1)
		start_live_philo(&all);
	return(0);

}