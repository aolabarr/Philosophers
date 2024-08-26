/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:07:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/26 18:09:37 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*dinner_start(t_data *data)
{
	int	i;

	if (pthread_create(&data->monitor, NULL, run_monitor, (void *)data) != 0)
		return (handle_error(data, THREAD), NULL);
	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, run_philo,
				(void *)&data->philos[i]) != 0)
			return (handle_error(data, THREAD), NULL);
		i++;
	}
	i = 0;
	while (i < data->nbr_philos)
	{
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
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)input;
	data = (t_data *)philo->data;
	if (philo->id % 2 == 0)
		usleep(SLEEP_EVEN * 1000);
	pthread_mutex_lock(&data->die_mutex);
	while (philo->full == 0 && data->die == 0)
	{
		pthread_mutex_unlock(&data->die_mutex);
		do_action(data, philo, GET_F_FORK);
		do_action(data, philo, GET_S_FORK);
		do_action(data, philo, EAT);
		do_action(data, philo, SLEEP);
		do_action(data, philo, THINK);
		pthread_mutex_lock(&data->die_mutex);
	}
	pthread_mutex_unlock(&data->die_mutex);
	return (NO_NULL);
}

int	do_action(t_data *data, t_philo *philo, int type)
{
	if (is_someone_dead(data))
		return (0);
	if (type == GET_F_FORK)
		get_fork(philo, FIRST);
	else if (type == GET_S_FORK)
		get_fork(philo, SECOND);
	if (type == EAT)
		eat(data, philo);
	else if (type == SLEEP)
		sleep_action(data, philo);
	else if (type == THINK)
		printf("%ld %d is thinking\n", ft_gettimeofday(), philo->id);
	return (0);
}

int	is_someone_dead(t_data *data)
{
	pthread_mutex_lock(&data->die_mutex);
	if (data->die == 1)
	{
		pthread_mutex_unlock(&data->die_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->die_mutex);
	return (0);
}
