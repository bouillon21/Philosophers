#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define RED			"\033[1;31m"
# define RESET			"\033[0m"
# define YELLOW			"\033[1;33m"

typedef struct s_axioms
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_meals;
}				t_axioms;

typedef struct s_all
{
	t_axioms	axioms;
}				t_all;

#endif
