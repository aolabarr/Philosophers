/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/09/25 18:40:09 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->time_mutex);
	philo->last_time = ft_gettimeofday();
	pthread_mutex_unlock(&data->time_mutex);
	if (is_someone_dead(data))
	{
		pthread_mutex_unlock(&philo->s_fork->mutex);
		pthread_mutex_unlock(&philo->f_fork->mutex);
		return (0);	
	}
	printf("%ld %d is eating\n", philo->last_time - data->time_zero, philo->id);
	usleep(data->time_eat * 1000);
	philo->meals += 1;
	if (philo->meals == data->nbr_meals)
	{
		pthread_mutex_lock(&data->full_mutex);
		philo->full = 1;
		pthread_mutex_unlock(&data->full_mutex);
	}
	pthread_mutex_unlock(&philo->s_fork->mutex);
	pthread_mutex_unlock(&philo->f_fork->mutex);
	return (0);
}

void	sleep_action(t_data *data, t_philo *philo)
{
	if (!is_someone_dead(data))
		printf("%ld %d is sleeping\n", ft_gettimeofday() - data->time_zero, philo->id);
	else
		return ;
	usleep(data->time_sleep * 1000);
	return ;
}

int	get_fork(t_data *data, t_philo *philo, int type)
{
	if (type == FIRST)
	{
		pthread_mutex_lock(&philo->f_fork->mutex);
		if (!is_someone_dead(data))
			printf("%ld %d has taken a fork\n", ft_gettimeofday() - data->time_zero, philo->id);
		else
			return (pthread_mutex_unlock(&philo->f_fork->mutex), 0);
	}
	else if (type == SECOND)
	{
		pthread_mutex_lock(&philo->s_fork->mutex);	
		if (!is_someone_dead(data))
			printf("%ld %d has taken a fork\n", ft_gettimeofday() - data->time_zero, philo->id);
		else
			return (pthread_mutex_unlock(&philo->f_fork->mutex), 0);
	}
	return (0);
}
