/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:04:17 by aolabarr          #+#    #+#             */
/*   Updated: 2024/09/25 17:01:59 by aolabarr         ###   ########.fr       */
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

	ptr = malloc(bytes);
	if (!ptr)
		handle_error(data, MALLOC);
	return (ptr);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && (i < n))
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (s1[i] - str2[i]);
		i++;
	}
	return (0);
}
