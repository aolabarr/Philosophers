/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:27:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/10/02 18:54:34 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*run_monitor(void *input)
{
	t_data	*data;

	data = (t_data *)input;
	while (data->full == 0)
	{
		if (check_status(data) == DEAD)
			break ;
	}
	if (data->full == 1)
	{
		usleep(FINAL_WAIT * 1000);
		printf("All philosophers are already full\n");
	}
	return (NO_NULL);
}

int	check_status(t_data *data)
{
	int		i;
	int		all_full;

	i = 0;
	all_full = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_lock(&data->full_mutex);
		all_full += data->philos[i].full;
		pthread_mutex_unlock(&data->full_mutex);
		if (all_full == data->nbr_philos)
		{
			pthread_mutex_lock(&data->all_full_mutex);
			data->full = 1;
			pthread_mutex_unlock(&data->all_full_mutex);
		}
		if (is_dead_calcule(data, i))
			return (DEAD);
		i++;
	}
	return (0);
}

int	is_dead_calcule(t_data *data, int i)
{
	size_t	time_interval;

	pthread_mutex_lock(&data->time_mutex);
	time_interval = ft_gettimeofday() - data->philos[i].last_time;
	pthread_mutex_unlock(&data->time_mutex);
	pthread_mutex_lock(&data->full_mutex);
	if (data->philos[i].full == 0 && time_interval > data->time_die)
	{
		pthread_mutex_unlock(&data->full_mutex);
		pthread_mutex_lock(&data->die_mutex);
		data->die = 1;
		pthread_mutex_unlock(&data->die_mutex);
		printf("%ld\tPhilo %d is dead\n",
			ft_gettimeofday() - data->time_zero, data->philos[i].id);
		return (1);
	}
	pthread_mutex_unlock(&data->full_mutex);
	return (0);
}
