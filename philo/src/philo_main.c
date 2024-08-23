/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:48 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/23 17:47:32 by aolabarr         ###   ########.fr       */
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
	//final_info(&data);
	free_all(&data);
	printf("Prueba FIN\n");
	return (0);
}

void	free_all(t_data *data)
{
	int i;
	if (!data)
		return ;
	
	if (data->philos)
		free(data->philos);
	i = 0;
	while(++i < data->nbr_philos)
		pthread_mutex_destroy(&data->forks[i].mutex);
	if (data->forks)
		free(data->forks);
	data->philos = NULL;
	data->forks = NULL;
	return ;
}

