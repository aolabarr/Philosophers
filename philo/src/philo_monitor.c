/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:27:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/26 18:12:06 by aolabarr         ###   ########.fr       */
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
			data->full = 1;
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
	if (data->philos[i].meals > 0 && data->philos[i].full == 0
		&& time_interval > data->time_die)
	{
		pthread_mutex_lock(&data->die_mutex);
		printf("%ld %d is dead\n", ft_gettimeofday(), data->philos[i].id);
		data->die = 1;
		pthread_mutex_unlock(&data->die_mutex);
		return (1);
	}
	return (0);
}
