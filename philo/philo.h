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
# define BLUE			"\x1b[34m"
# define GREEN			"\x1b[32m"
# define WHITE			"\033[1;39m"

typedef pthread_mutex_t mutex_t;
mutex_t	g_chat;

typedef struct s_axioms
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_meals;
}				t_axioms;

typedef struct s_philo
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_meals;
	long			start_time;
	long			start_life;

	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}				t_philo;


typedef struct s_all
{
	long int	start_time;
	t_philo		*philo;
	t_axioms	axioms;
}				t_all;

int	check_args(int argc, char **argv, t_all *all);
long int	ft_atoi(const char *str);
int	print_error(char *str);
void	my_usleep(long time);
long	get_time(void);
void	ft_putnbr(long int n);
void	init_philo(t_all *all);
int	init(int argc, char **argv, t_all *all);

void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	get_fork(t_philo *philo, mutex_t *first, mutex_t *second);
void	throw_fork(t_philo *philo, mutex_t *first, mutex_t *second);


#endif
