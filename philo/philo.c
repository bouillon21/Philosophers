#include "philo.h"

static	int	check_death(t_all *all, int *did_everyone_eat, int i)
{
	if (all->axioms.time_to_die < get_time() - all->philo[i].start_life)
	{
		pthread_mutex_lock(&g_chat);
		printf("%s⏰%zu\t|%d|\t💀died💀\n", RED,
			get_time() - all->philo[i].start_time, i + 1);
		return (1);
	}
	if (all->philo[i].number_meals == 0)
		--*did_everyone_eat;
	return (0);
}

void	*surveillance(void *all)
{
	int		i;
	int		did_everyone_eat;
	t_all	*all_tmp;

	all_tmp = all;
	while (1)
	{
		i = -1;
		did_everyone_eat = all_tmp->axioms.number_of_philosophers;
		while (++i < all_tmp->axioms.number_of_philosophers)
		{
			if (check_death(all_tmp, &did_everyone_eat, i))
				return (NULL);
		}
		if (did_everyone_eat == 0)
		{
			pthread_mutex_lock(&g_chat);
			return (NULL);
		}
	}
	return (NULL);
}

void	*philo(void *curent_philo)
{
	t_philo	*philo;
	t_mutex	*first;
	t_mutex	*second;

	philo = (t_philo *)curent_philo;
	first = philo->left;
	second = philo->right;
	if (philo->philo_num % 2 == 0)
	{
		first = philo->right;
		second = philo->left;
	}
	while (1)
	{
		get_fork(philo, first, second);
		philo_eat(philo);
		throw_fork(philo, first, second);
		if (philo->number_meals != -1)
			if (philo->number_meals != 0)
				--philo->number_meals;
		philo_sleep(philo);
	}
	return (NULL);
}

void	start_live_philo(t_all *all)
{
	int			i;
	pthread_t	*thread;
	pthread_t	observer;

	i = -1;
	thread = malloc(sizeof(pthread_t) * all->axioms.number_of_philosophers + 1);
	pthread_create(&observer, NULL, surveillance, (void *)all);
	while (++i < all->axioms.number_of_philosophers)
		pthread_create(&thread[i], NULL, philo, (void *)&all->philo[i]);
	pthread_join(observer, NULL);
	pthread_mutex_destroy(&g_chat);
	free(thread);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (init(argc, argv, &all) != -1)
		start_live_philo(&all);
	free(all.philo);
	return (0);
}
