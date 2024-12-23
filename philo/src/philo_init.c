/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:48:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/10/02 18:48:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*init_data(int ac, char **av, t_data *data)
{
	data->nbr_philos = ftph_atoi(av[1]);
	data->time_die = ftph_atoi(av[2]);
	data->time_eat = ftph_atoi(av[3]);
	data->time_sleep = ftph_atoi(av[4]);
	if (ac == 6)
		data->nbr_meals = ftph_atoi(av[5]);
	else
		data->nbr_meals = NO_MEALS;
	if (!init_mutex(data))
		return (NULL);
	if (!init_philos(data))
		return (NULL);
	data->die = 0;
	data->full = 0;
	if (!init_time(data))
		return (NULL);
	return (NO_NULL);
}

char	*init_philos(t_data *data)
{
	int	i;

	data->philos = ft_malloc(data, sizeof(t_philo) * data->nbr_philos);
	if (!data->philos)
		return (NULL);
	i = 0;
	while (i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		assign_forks(data, i);
		data->philos[i].meals = 0;
		data->philos[i].full = 0;
		data->philos[i].last_time = ft_gettimeofday();
		data->philos[i].data = (void *)data;
		i++;
	}
	return (NO_NULL);
}

char	*init_time(t_data *data)
{
	int	i;

	i = 0;
	data->time_zero = ft_gettimeofday();
	while (i < data->nbr_philos)
	{
		data->philos[i].last_time = ft_gettimeofday();
		i++;
	}
	return (NO_NULL);
}

void	assign_forks(t_data *data, int i)
{
	int	num;

	num = (i + 1) % data->nbr_philos;
	data->philos[i].f_fork = &data->forks[num];
	data->philos[i].s_fork = &data->forks[i];
	return ;
}

char	*init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_fork) * data->nbr_philos);
	if (!data->forks)
		return (handle_error(data, MALLOC), NULL);
	i = 0;
	while (i < data->nbr_philos)
	{
		data->forks[i].id = i;
		if (pthread_mutex_init(&data->forks[i].mutex, NULL) != 0)
			return (handle_error(data, MUTEX), NULL);
		i++;
	}
	if (pthread_mutex_init(&data->all_full_mutex, NULL) != 0)
		return (handle_error(data, MUTEX), NULL);
	if (pthread_mutex_init(&data->full_mutex, NULL) != 0)
		return (handle_error(data, MUTEX), NULL);
	if (pthread_mutex_init(&data->die_mutex, NULL) != 0)
		return (handle_error(data, MUTEX), NULL);
	if (pthread_mutex_init(&data->time_mutex, NULL) != 0)
		return (handle_error(data, MUTEX), NULL);
	return (NO_NULL);
}
