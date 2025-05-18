/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:54:50 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/19 00:33:40 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d has taken a fork\n", (get_time() - philo->data->start_time), philo->id);
	printf("%lld %d has taken a fork\n", (get_time() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	drop_fork(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d is eating\n", (get_time() - philo->data->start_time), philo->id);
	printf("%lld %d is eating\n", (get_time() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo->last_time_eat = get_time();
	philo->meals_eaten++;
	drop_fork(philo);
}



void	*philos_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;
	while(1)
	{
		take_fork(philo);
		philo_eat(philo);
	}
	// drop_fork(philo);
	return (NULL);
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	while(i < data->num_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, philos_routine, &data->philos[i]);
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
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
}