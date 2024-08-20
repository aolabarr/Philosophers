/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:04:17 by aolabarr          #+#    #+#             */
/*   Updated: 2024/08/20 21:08:39 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ftph_atoi(const char *str)
{
	size_t		i;
	long int	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

void	ftph_putendl(char *s)
{
	write(STDOUT_FILENO, s, ftph_strlen(s));
	write(STDOUT_FILENO, "\n", 1);
}

size_t	ftph_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	*ft_malloc(t_data *data, int bytes)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(bytes);
	if (!ptr) 
		handle_error(data, MALLOC);
	return (ptr);
}

