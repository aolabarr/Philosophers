/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:11:30 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/20 21:16:30 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*check_input(int ac, char **av, t_data *data)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (handle_error(NULL, INPUT), NULL);
	i = 1;
	while (i < ac)
	{
		if (!str_is_digit(av[i]))
			handle_error(NULL, INPUT);
		i++;
	}
	data->nbr_philos = ftph_atoi(av[1]);
	data->time_die = ftph_atoi(av[2]);
	data->time_eat = ftph_atoi(av[3]);
	data->time_sleep = ftph_atoi(av[4]);
	if (ac == 6)
		data->nbr_meals = ftph_atoi(av[5]);
	else
		data->nbr_meals = NO_MEALS;
	return ("1");
}

void	handle_error(t_data *data, int type)
{
	if (type == INPUT)
		ftph_putendl(INPUT_ERROR_MESSAGE);
	else if (type == MALLOC)
		ftph_putendl(MALLOC_ERROR_MESSAGE);
	else if (type == MUTEX)
		ftph_putendl(MUTEX_ERROR_MESSAGE);
	else if (type == THREAD)
		ftph_putendl(THREAD_ERROR_MESSAGE);
	free_all(data);
	return ;
}

int	str_is_digit(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
