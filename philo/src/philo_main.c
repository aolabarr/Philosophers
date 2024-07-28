/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:48 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/28 15:33:50 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_input(ac, av, &data);
	return (0);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	return ;
}
