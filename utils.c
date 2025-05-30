/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:48:07 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/22 00:48:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

int	ft_atoi(char *nptr)
{
	char	*ptr;
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	ptr = (char *)nptr;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (sign * result);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

void	print_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("number of arguments is incorrect\n", 2);
	if (flag == 2)
		ft_putstr_fd("the arguments should be numbers\n", 2);
	if (flag == 3)
		ft_putstr_fd("the arguments should be > 0\n", 2);
}

long long	get_time_now(t_data *data)
{
	struct timeval tv;
	long long timestamp;
	long long current_time;

	if (gettimeofday(&tv, NULL) == 0)
	{
		timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}
	current_time = timestamp - data->start_time;
	return(current_time);
}