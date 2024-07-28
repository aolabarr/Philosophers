/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:11:30 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/28 15:34:58 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_input(int ac, char **av, t_data *data)
{
	int	i;

	if (ac < 4 || ac > 5)
		handle_error(NULL, INPUT);
	i = 1;
	while (i < ac)
	{
		if (!str_is_digit(av[i]))
			handle_error(NULL, INPUT);
		i++;
	}
	data->time_die = ftph_atoi(av[1]);
	data->time_eat = ftph_atoi(av[2]);
	data->time_sleep = ftph_atoi(av[3]);
	if (ac == 5)
		data->n = ftph_atoi(av[4]);
	else
		data->n = 0;
	return ;
}

void	handle_error(t_data *data, int type)
{
	if (type == INPUT)
		perror(INPUT_ERROR_MESSAGE);
	else if (type == MALLOC)
		perror(MALLOC_ERROR_MESSAGE);
	free_all(data);
	exit(EXIT_FAILURE);
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
