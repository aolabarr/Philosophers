/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:48 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/26 18:20:58 by aolabarr         ###   ########.fr       */
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
