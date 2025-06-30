#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
#include <sys/time.h>

typedef struct s_args
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long			start_time;            // idk
	pthread_mutex_t *forks;     // the lock array
	pthread_mutex_t write_lock; // idk
	int				someone_died;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	pthread_t		thread;
	t_args			*args;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}					t_philo;

long	start_time(void);
void    ft_sleep(long sleep_time);
long	get_current_time(void);
t_args				**args_func(void);
void				init_args(char **argv);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(void);
void				new_node(t_philo *node);
int					ft_atoi(const char *str);
t_philo				**philo_list(void);
void				*routine(void *arg);
void				fill_list(char **argv);
#endif
