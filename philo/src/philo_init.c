/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:48:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/20 21:01:04 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(t_data *data)
{
	int i;
	int num;

	data->philos = ft_malloc(data, sizeof(t_philo) * data->nbr_philos);
	i = 0;
	while (i < data->nbr_philos)
	{
		data->philos[i].id = i;
		num = (i + 1) % data->nbr_philos;
		if (i % 2 == 0)
		{
			data->philos[i].f_fork = &data->forks[i];
			data->philos[i].s_fork = &data->forks[num];
		}
		else
		{
			data->philos[i].f_fork = &data->forks[num];
			data->philos[i].s_fork = &data->forks[i];
		}
		data->philos[i].full = 0;
		data->philos[i].last_time = 0;
		data->philos[i].data = (void *)data;
		i++;
	}
	return ;
}

void	init_forks(t_data *data)
{
	int i;

	data->forks = malloc(sizeof(t_fork) * data->nbr_philos);
	if (!data->forks)
		handle_error(data, MALLOC);
	i = 0;
	while (i < data->nbr_philos)
	{
		data->forks[i].id = i;
		if (pthread_mutex_init(&data->forks[i].mutex, NULL) != 0)
			handle_error(data, MUTEX);
		i++;
	}
	return ;
}

void	dinner_start(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nbr_philos)
	{
		write(1, "Prueba AA\n", 10);
		if (pthread_create(data->philos[i].thread, NULL, run_philo, (void *)&data->philos[i]) != 0)
			handle_error(data, THREAD);
		write(1, "Prueba BB\n", 10);
		if (pthread_join(*data->philos[i].thread, NULL) != 0)
			handle_error(data, JOIN);
		i++;
	}
	return ;
}
void	*run_philo(void *input)
{
	t_philo philo;

	printf("Prueba AAA\n");
	philo = *(t_philo *)input;
	printf("Thread: %d\n", philo.id);
	usleep(100);
	return (NULL);
}
