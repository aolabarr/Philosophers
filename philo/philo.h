/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:34:43 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/28 15:34:17 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	n;
}				t_data;

# define INPUT_ERROR_MESSAGE		"Incorrect arguments"
# define MALLOC_ERROR_MESSAGE		"Memory allocation error"

# define INPUT		1
# define MALLOC		2

void	free_all(t_data *data);

// ERRORS
void	check_input(int ac, char **av, t_data *data);
void	handle_error(t_data *data, int type);
int		str_is_digit(char *str);

// UTILS
size_t	ftph_strlen(const char *str);
void	ftph_putendl(char *s);
int		ftph_atoi(const char *str);

#endif
