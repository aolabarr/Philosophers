/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:48:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/22 15:33:46 by marvin           ###   ########.fr       */
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
	if (!init_forks(data))
		return (NULL);
	if (!init_philos(data))
		return (NULL);
	data->die = 0;
	printf("data->die: %d\n", data->die);
	data->full = 0;
	return (NO_NULL);
}

char	*init_philos(t_data *data)
{
	int i;
	int num;

	data->philos = ft_malloc(data, sizeof(t_philo) * data->nbr_philos);
	if (!data->philos)
		return (NULL);
	i = 0;
	while (i < data->nbr_philos)
	{
		data->philos[i].id = i;
		num = (i + 1) % data->nbr_philos;
		data->philos[i].f_fork = &data->forks[num];
		data->philos[i].s_fork = &data->forks[i];
		if (i % 2 == 0)
		{
			data->philos[i].f_fork = &data->forks[i];
			data->philos[i].s_fork = &data->forks[num];
		}
		data->philos[i].meals = 0;
		data->philos[i].full = 0;
		data->philos[i].last_time = SIZE_MAX;
		data->philos[i].data = (void *)data;
		i++;
	}
	return (NO_NULL);
}

char	*init_forks(t_data *data)
{
	int i;

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
	return (NO_NULL);
}

size_t	ft_gettimeofday(void)
{
	struct timeval	tv;
	size_t			mstime;

	gettimeofday(&tv, NULL);
	mstime = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (mstime);
}
