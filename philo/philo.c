#include "philo.h"

int	main(int argc, char **argv)
{
	t_all	all;
	pthread_t	*thread;

	check_args(argc, argv, &all);
	thread = malloc(sizeof(pthread_t *) * all.axioms.number_of_philosophers + 1);
	
}