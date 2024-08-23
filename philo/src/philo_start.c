/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:07:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/22 18:35:07 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*dinner_start(t_data *data)
{
	int	i;

	if (pthread_create(&data->monitor, NULL, run_monitor, (void *)data) != 0)
			return (handle_error(data, THREAD), NULL);
	i = 0;
	while(i < data->nbr_philos)
	{
		printf("Prueba D %d\n", i);
		if (pthread_create(&data->philos[i].thread, NULL, run_philo, (void *)&data->philos[i]) != 0)
			return (handle_error(data, THREAD), NULL);
		i++;
	}
	i = 0;
	while(i < data->nbr_philos)
	{
		printf("Prueba E %d\n", i);
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (handle_error(data, JOIN), NULL);
		i++;
	}
	if (pthread_join(data->monitor, NULL) != 0)
			return (handle_error(data, JOIN), NULL);
	return (NO_NULL);
}
void	*run_philo(void *input)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)input;
	data = (t_data *)philo->data;
	printf("Thread INIT: %d, full, die: (%d, %d)\n", philo->id, data->full, data->die);
	
	while (philo->full == 0 && data->die == 0)
	{
		eat(philo); //adquirir mutex + comer
		printf("%ld %d is sleeping\n", ft_gettimeofday(), philo->id);
		usleep(data->time_sleep * 1000 *10); sched_yield();
		printf("%ld %d is thinking\n", ft_gettimeofday(), philo->id);	
	}
	
	return (NO_NULL);
}

void	*run_monitor(void *input)
{
    t_data	*data;
	int		all_full;
	int		i;

	data = (t_data *)input;
	while (data->full == 0 && data->die == 0)
	{
		i = 0;
		all_full = 0;
		while (i < data->nbr_philos)
		{
			if (all_full == data->nbr_philos)
				data->full = 1;
			if (data->philos[i].meals == data->nbr_meals)
				data->philos[i].full = 1;
			all_full += data->philos[i].full;
			if (data->philos[i].meals > 0 && ft_gettimeofday() - data->philos[i].last_time > data->time_die)
			{
				data->die = 1;
				return (NO_NULL);
			}	
			i++;
		}
		usleep(SLEEP_MONITOR * 1000);
	}
	return (NO_NULL);
}

void	eat(t_philo *philo)
{
	int	time;

	time = ((t_data *)philo->data)->time_eat;

	pthread_mutex_lock(&philo->f_fork->mutex);
	printf("%ld %d has taken a fork\n", ft_gettimeofday(), philo->id);
	pthread_mutex_lock(&philo->s_fork->mutex);
	printf("%ld %d has taken a fork\n", ft_gettimeofday(), philo->id);

	printf("%ld %d is eating ********************\n", ft_gettimeofday(), philo->id);
	usleep(time * 1000);
	philo->last_time = ft_gettimeofday();
	philo->meals += 1;
	
	pthread_mutex_unlock(&philo->s_fork->mutex);
	pthread_mutex_unlock(&philo->f_fork->mutex);
	
}
