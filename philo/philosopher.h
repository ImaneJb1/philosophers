/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:53:10 by ijoubair          #+#    #+#             */
/*   Updated: 2025/07/02 14:44:08 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_args
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long start_time;        // idk
	pthread_mutex_t *forks; // the lock array
	pthread_mutex_t	write_lock;
	// idk
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
	pthread_mutex_t	current_time;
	;
	pthread_mutex_t	last_meal_lock;
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
int					*death(void);
t_args				**args_func(void);
t_philo				**philo_list(void);

//		routine
void				ft_sleep(long sleep_time);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				*routine(void *arg);

//		routine utils
void				am_i_dead(t_philo *philo);
int					get_last_meal(t_philo *philo);

int					is_dead(void);

//		printers
void				print_func(int id, char *str);

//		parsing
int					check_args(int argc, char **argv);
void				parsing(int argc, char **argv);
//		monitor
void				mentor(void);
#endif
