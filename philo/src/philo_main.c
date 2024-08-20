/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:48 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/20 21:14:23 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	printf("Prueba A\n");
	if (!check_input(ac, av, &data))
		return (1);
	printf("Prueba B\n");
	init_forks(&data);
	printf("Prueba C\n");
	init_philos(&data);
	printf("Prueba D\n");
	dinner_start(&data);
	printf("Prueba E\n");
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
	return ;
}
