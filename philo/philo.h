/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:34:43 by aolabarr          #+#    #+#             */
/*   Updated: 2024/10/02 18:56:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

typedef pthread_mutex_t	t_mtx;

typedef struct s_forks
{
	int		id;	
	t_mtx	mutex;
}			t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_fork		*f_fork;
	t_fork		*s_fork;
	int			meals;
	int			full;
	size_t		last_time;
	void		*data;
}				t_philo;

typedef struct s_data
{
	int			nbr_philos;
	size_t		time_die;
	int			time_eat;
	int			time_sleep;
	int			nbr_meals;
	pthread_t	monitor;
	t_philo		*philos;
	t_fork		*forks;
	int			die;
	t_mtx		die_mutex;
	int			full;
	t_mtx		all_full_mutex;
	t_mtx		full_mutex;
	t_mtx		time_mutex;
	int			all_create;
	size_t		time_zero;
}			t_data;

# define INPUT_ERROR_MESSAGE		"Incorrect arguments"
# define MALLOC_ERROR_MESSAGE		"Memory allocation error"
# define MUTEX_ERROR_MESSAGE		"Mutex creation error"
# define THREAD_ERROR_MESSAGE		"Thread creation error"

# define MAXINT_STR	"2147483647"
# define MININT_STR	"-2147483648"
# define NO_MEALS	-1
# define NO_NULL	""
# define SLEEP_EVEN	10
# define FINAL_WAIT 1000

# define FIRST		1
# define SECOND		2

# define GET_F_FORK	10
# define GET_S_FORK	11
# define EAT		12
# define SLEEP		13
# define THINK		14
# define DEAD		15
# define NOTHING	16

# define INPUT		1
# define MALLOC		2
# define MUTEX		3
# define THREAD		4
# define JOIN		5

void	final_info(t_data *data);
void	philo_info(t_philo *philo);

//MAIN
void	free_all(t_data *data);
char	*one_philosopher(t_data *data);
void	*run_one_philo(void *input);

// ERRORS
char	*check_input(int ac, char **av);
void	handle_error(t_data *data, int type);
int		str_is_digit(char *str);
int		ft_str_is_int(char *str);

// UTILS
size_t	ftph_strlen(const char *str);
void	ftph_putendl(char *s);
int		ftph_atoi(const char *str);
void	*ft_malloc(t_data *data, int bytes);
int		ft_strncmp(char *s1, char *s2, size_t n);

//INIT
char	*init_data(int ac, char **av, t_data *data);
char	*init_philos(t_data *data);
void	assign_forks(t_data *data, int i);
char	*init_mutex(t_data *data);
char	*init_time(t_data *data);

//START
char	*dinner_start(t_data *data);
void	*run_philo(void *input);
int		do_action(t_data *data, t_philo *philo, int type);
int		is_someone_dead(t_data *data);
int		is_all_philo_full(t_data *data);

//MONITOR
void	*run_monitor(void *input);
int		check_status(t_data *data);
int		is_dead_calcule(t_data *data, int i);

// ACTIONS
void	sleep_action(t_data *data, t_philo *philo);
int		eat(t_data *data, t_philo *philo);
int		get_fork(t_data *data, t_philo *philo, int type);
size_t	ft_gettimeofday(void);

#endif