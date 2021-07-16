#include "philo.h"

int	check_args(int argc, char **argv, t_all *all)
{
	if (argc != 5 && argc != 6)
		return (print_error("🤯Philosophers do not like this number arguments"));
	all->axioms.number_of_philosophers = ft_atoi(argv[1]);
	if(all->axioms.number_of_philosophers == 1)
		return (print_error("🤓How will a philosopher eat with one fork?!?!?🤓"));
	all->axioms.time_to_die = ft_atoi(argv[2]);
	all->axioms.time_to_eat = ft_atoi(argv[3]);
	all->axioms.time_to_sleep = ft_atoi(argv[4]);
	all->axioms.number_meals = -1;
	if (argc == 6)
		all->axioms.number_meals = ft_atoi(argv[5]);
	else
		all->axioms.number_meals = -1;
	if (all->axioms.time_to_die < 1 || all->axioms.number_of_philosophers < 1 ||
			all->axioms.time_to_eat < 1 || all->axioms.time_to_sleep < 1
				|| all->axioms.number_meals == 0)
		return (print_error("🤬Your arguments are complete shit🤬"));
	return (0);
}

void init_philo(t_all *all)
{
	int	i;

	i = -1;
	all->philo = malloc(sizeof(t_philo) * all->axioms.number_of_philosophers + 1);
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
	if (check_args(argc, argv, all) == -1)
		return(-1);
	all->start_time = get_time();
	pthread_mutex_init(&g_chat, NULL);
	init_philo(all);
	return (0);
}
