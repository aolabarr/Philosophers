/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:27:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/23 17:46:03 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*run_monitor(void *input)
{
    t_data	*data;

	data = (t_data *)input;
	while (data->full == 0)
	{
		if (check_status(data) == DEAD)
			break ;
	}
	return (NO_NULL);
}

int	check_status(t_data *data)
{
	int		i;
	int		all_full;
	
	i = 0;
	all_full = 0;
	while (i < data->nbr_philos)
	{
		if (data->philos[i].meals == data->nbr_meals)
			data->philos[i].full = 1;
		all_full += data->philos[i].full;
		if (all_full == data->nbr_philos)
			data->full = 1;
		if (is_dead(data, i))
			return (1);
		i++;
	}
	//final_info(data);
	return (0);
}

int	is_dead(t_data *data, int i)
{
	size_t	time_interval;

	time_interval = ft_gettimeofday() - data->philos[i].last_time;
	if (data->philos[i].meals > 0 && data->philos[i].full == 0 && time_interval > data->time_die)
	{
		data->die = 1;
		data->philos[i].die = 1;
		//printf("DIE: %zu, %zu\n", time_interval, data->time_die);
		return (1);
	}
	return (0);
}
