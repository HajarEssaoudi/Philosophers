/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:54:50 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/18 02:57:24 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while(i < data->num_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, philos_routine, &data->philos[i]);
		usleep(50);
		i++;
	}
}