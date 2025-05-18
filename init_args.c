/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:49:55 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/18 02:43:52 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->time_must_eat = ft_atoi(av[5]);
	else
		data->time_must_eat = -1;
	data->start_time = get_time();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	while(i < data->num_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_data *data)
{
	int i;

	i = 0;
	data->philos = malloc(sizeof(t_philosopher) * data->num_philo);
	if (!data->philos)
	{
		printf("failed to allocate\n");
		clean_up(data);
		exit(1);
	}
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_time_eat = data->start_time;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];

		i++;
	}
}