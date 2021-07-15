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
	return (1);
}
