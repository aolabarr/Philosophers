/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/26 18:07:26 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->time_mutex);
	philo->last_time = ft_gettimeofday();
	pthread_mutex_unlock(&data->time_mutex);
	printf("%ld %d is eating\n", philo->last_time, philo->id);
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
	return ;
}

void	sleep_action(t_data *data, t_philo *philo)
{
	printf("%ld %d is sleeping\n", ft_gettimeofday(), philo->id);
	usleep(data->time_sleep * 1000);
}

void	get_fork(t_philo *philo, int type)
{
	if (type == FIRST)
	{
		pthread_mutex_lock(&philo->f_fork->mutex);
		printf("%ld %d has taken a fork\n", ft_gettimeofday(), philo->id);
	}
	else if (type == SECOND)
	{
		pthread_mutex_lock(&philo->s_fork->mutex);
		printf("%ld %d has taken a fork\n", ft_gettimeofday(), philo->id);
	}
	return ;
}
