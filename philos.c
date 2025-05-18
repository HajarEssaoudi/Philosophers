/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:54:50 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/18 16:14:19 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;
	pthread_mutex_lock(&philo->print_mutex);
	printf("Hello I am philo number %d\n", philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
	return (NULL);
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	// data->start_time = get_time();
	// printf("%lld\n", data->start_time);
	pthread_mutex_init(&data->philos->print_mutex, NULL);
	while(i < data->num_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, philos_routine, &data->philos[i]);
		usleep(50);
		i++;
	}
}

void	destroy_philos(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		usleep(50);
		i++;
	}
	pthread_mutex_destroy(&data->philos->print_mutex);
}