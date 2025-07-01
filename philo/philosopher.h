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
	pthread_mutex_t death_lock; // idk

	int				someone_died;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	int				death;
	pthread_t		thread;
	t_args			*args;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}					t_philo;

// 		time funtions
long				start_time(void);
long				get_current_time(void);

void				init_args(char **argv);
void				new_node(t_philo *node);
int					ft_atoi(const char *str);
void				fill_list(char **argv);
//		globales
int 				*death(void);
t_args				**args_func(void);
t_philo				**philo_list(void);

//		routine
void    			ft_sleep(long sleep_time);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				*routine(void *arg);

//		routine utils
void 				am_i_dead(t_philo *philo);

int					is_dead(void);

//		printers
void				print_func(long time, int id, char *str);
#endif
