typedef struct s_args {
    int philo_count;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_count;
    long start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t write_lock;
    int someone_died;
} t_args;

typedef struct s_philo {
    int id;
    int eat_count;
    long last_meal;
    pthread_t thread;
    t_args *args;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} t_philo;


while (!args->someone_died)
{
    take_forks();
    eat();
    put_down_forks();
    sleep();
    think();
}
