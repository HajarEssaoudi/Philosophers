/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:54:50 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/22 01:15:58 by root             ###   ########.fr       */
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
	printf("%lld %d has taken a fork\n", (get_time_now(philo->data)), philo->id);
	printf("%lld %d has taken a fork\n", (get_time_now(philo->data)), philo->id);
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
	printf("%lld %d is eating\n", (get_time_now(philo->data)), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_time_eat = get_time_now(philo->data);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_mutex);
	usleep(philo->data->time_to_eat * 1000);
}

	int	philo_died(t_philosopher *philo)
	{
		int is_dead;

		is_dead = 0;
		pthread_mutex_lock(philo->meal_mutex);
		if ((get_time_now(philo->data) - philo->last_time_eat) > philo->data->time_to_die)
			is_dead = 1;
		pthread_mutex_unlock(philo->meal_mutex);
		if(is_dead)
		{
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%lld %d died\n", (get_time_now(philo->data)), philo->id);
			philo->data->someone_died = 1;
			pthread_mutex_unlock(&philo->data->print_mutex);
		}
		return (is_dead);
	}

void	philo_think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d is thinking\n", get_time_now(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(100);
}

void	philo_sleep(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d is sleeping\n", (get_time_now(philo->data)), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep * 1000);
}

void	*philos_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;
	while(!philo->data->someone_died)
	{
		if(philo_died(philo))
			break;
		if (philo->data->time_must_eat > 0
			&& philo->meals_eaten >= philo->data->time_must_eat)
			break;
		take_fork(philo);
		philo_eat(philo);
		drop_fork(philo);
		if(philo_died(philo))
			break;
		philo_sleep(philo);
		if(philo_died(philo))
			break;
		philo_think(philo);
	}
	return (NULL);
}

void *death_checker_routine(t_data *data)
{
	
}

void	create_philos(t_data *data)
{
	int	i;
	pthread_t death_checker;

	i = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_check, NULL);
	pthread_create(&death_checker, NULL, death_checker_routine, data);
	while(i < data->num_philo)
	{
		pthread_create(data->philos[i].thread, NULL, philos_routine, &data->philos[i]);
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
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_join(&data->death_check, NULL);
}