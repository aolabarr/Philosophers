/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:48 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/26 18:56:29 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_input(ac, av))
		return (EXIT_FAILURE);
	if (!init_data(ac, av, &data))
		return (EXIT_FAILURE);
	if (data.nbr_philos == 1)
		one_philosopher(&data);
	else
		dinner_start(&data);
	free_all(&data);
	return (0);
}

void	free_all(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->philos)
		free(data->philos);
	i = 0;
	while (++i < data->nbr_philos)
		pthread_mutex_destroy(&data->forks[i].mutex);
	if (data->forks)
		free(data->forks);
	data->philos = NULL;
	data->forks = NULL;
	pthread_mutex_destroy(&data->die_mutex);
	pthread_mutex_destroy(&data->full_mutex);
	pthread_mutex_destroy(&data->time_mutex);
	return ;
}
char	*one_philosopher(t_data *data)
{
	t_philo	philo;

	philo = data->philos[0];
	if (pthread_create(&philo.thread, NULL, run_one_philo, (void *)data) != 0)
		return (handle_error(data, THREAD), NULL);
	if (pthread_join(philo.thread, NULL) != 0)
		return (handle_error(data, JOIN), NULL);
	return (NO_NULL);
}

void	*run_one_philo(void *input)
{
	t_data	*data;
	size_t	time_interval;

	data = (t_data *)input;
	printf("%ld 1 has taken a fork\n", ft_gettimeofday());
	while (1)
	{
		time_interval = ft_gettimeofday() - data->philos[0].last_time;
		if (time_interval > data->time_die)
			break ;
	}
	printf("%ld 1 is dead\n", ft_gettimeofday());
	return (NO_NULL);
}

