/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:07:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/21 12:05:53 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*dinner_start(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nbr_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, run_philo, (void *)&data->philos[i]) != 0)
			return (handle_error(data, THREAD), NULL);
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (handle_error(data, JOIN), NULL);
		i++;
	}
	return (NO_NULL);
}
void	*run_philo(void *input)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)input;
	data = (t_data *)philo->data;
	printf("Thread INIT: %d\n", philo->id);
	
	while (philo->full == 0 && data->die == 0)
	{
		eat(philo, data->forks); //adquirir mutex + comer
		usleep(data->time_sleep);
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
			if (ft_gettimeofday() - data->philos[i].last_time > data->time_die)
			{
				data->die = 1;
				return (NO_NULL);
			}	
			i++;
		}
	}
	return (NO_NULL);
}

void	eat(t_philo *philo, t_fork *forks)
{
	
}
