#include "philo.h"

int	error_exit(char *str)
{
	printf("%s%s\n",RED, str);
	return(-1);
}

long int	ft_atoi(const char *str)
{
	int	i;
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
			if (str[i] != '\0')
				return (0);
		}
	}
	return (rez);
}

int	check_args(int argc, char **argv, t_all *all)
{
	if (argc != 5 && argc != 6)
		return (error_exit("🤯Philosophers do not like this number arguments"));
	all->axioms.number_of_philosophers = ft_atoi(argv[1]);
	if(all->axioms.number_of_philosophers == 1)
		return (error_exit("🤓How will a philosopher eat with one fork?!?!?🤓"));
	all->axioms.time_to_die = ft_atoi(argv[2]);
	all->axioms.time_to_eat = ft_atoi(argv[3]);
	all->axioms.time_to_sleep = ft_atoi(argv[4]);
	all->axioms.number_meals = -1;
	if (argc == 6)
		all->axioms.number_meals = ft_atoi(argv[5]);
	if (all->axioms.time_to_die < 1 || all->axioms.number_of_philosophers < 1 ||
			all->axioms.time_to_eat < 1 || all->axioms.time_to_sleep < 1
				|| all->axioms.number_meals == 0)
		return (error_exit("🤬Your arguments are complete shit🤬"));
	return (1);
}
