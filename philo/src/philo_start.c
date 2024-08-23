/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:07:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/23 17:44:52 by aolabarr         ###   ########.fr       */
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
		if (pthread_create(&data->philos[i].thread, NULL, run_philo, (void *)&data->philos[i]) != 0)
			return (handle_error(data, THREAD), NULL);
		i++;
	}
	i = 0;
	while(i < data->nbr_philos)
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
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)input;
	data = (t_data *)philo->data;
	if (philo->id % 2 == 0)
		usleep(SLEEP_EVEN * 1000);
	while (philo->full == 0 && data->die == 0)
	{
		eat(philo);
		if (data->die == 0)
			printf("%ld %d is sleeping\n", ft_gettimeofday(), philo->id);
		usleep(data->time_sleep * 1000);
		if (data->die == 0)
			printf("%ld %d is thinking\n", ft_gettimeofday(), philo->id);
		//philo_info(philo);
	}
	if (philo->die == 1)
		printf("%ld %d is dead\n", ft_gettimeofday(), philo->id);
	return (NO_NULL);
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = ((t_data *)philo->data);
	pthread_mutex_lock(&philo->f_fork->mutex);
	if (data->die == 0)
		printf("%ld %d has taken a fork\n", ft_gettimeofday(), philo->id);
	pthread_mutex_lock(&philo->s_fork->mutex);
	if (data->die == 0)
		printf("%ld %d has taken a fork\n", ft_gettimeofday(), philo->id);
	philo->last_time = ft_gettimeofday();
	if (data->die == 0)
		printf("%ld %d is eating\n", philo->last_time, philo->id);
	usleep(data->time_eat * 1000);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->s_fork->mutex);
	pthread_mutex_unlock(&philo->f_fork->mutex);
	return ;
}
