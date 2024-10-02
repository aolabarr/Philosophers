/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:11:30 by aolabarr          #+#    #+#             */
/*   Updated: 2024/10/02 17:53:19 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*check_input(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (handle_error(NULL, INPUT), NULL);
	i = 1;
	while (i < ac)
	{
		if (!(str_is_digit(av[i]) && ft_str_is_int(av[i])))
			return (handle_error(NULL, INPUT), NULL);
		if (ftph_atoi(av[i]) == 0)
			return (handle_error(NULL, INPUT), NULL);
		i++;
	}
	return (NO_NULL);
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

int	ft_str_is_int(char *str)
{
	if (str[0] != '-' && ftph_strlen(str) > 10)
		return (0);
	else if (str[0] != '-' && ftph_strlen(str) == 10)
	{
		if (ft_strncmp(MAXINT_STR, str, ftph_strlen(str)) < 0)
			return (0);
	}
	else if (str[0] == '-' && ftph_strlen(str) > 11)
		return (0);
	else if (str[0] == '-' && ftph_strlen(str) == 11)
	{
		if (ft_strncmp(MININT_STR, str, ftph_strlen(str)) < 0)
			return (0);
	}
	return (1);
}
