/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:48 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/21 11:57:44 by aolabarr         ###   ########.fr       */
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
	printf("Prueba FIN\n");
	return (0);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	data->philos = NULL;
	data->forks = NULL;
	return ;
}
