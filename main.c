/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:01:55 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/22 20:52:52 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_data *data)
{
	int i = 0;

	while (i < data->num_philo)
	{
		if (data->philos[i].meal_mutex)
		{
			pthread_mutex_destroy(data->philos[i].meal_mutex);
			free(data->philos[i].meal_mutex);
		}
		i++;
	}
	free(data->forks);
	free(data->philos);
}

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!check_args(ac, av))
		return (1);
	init_args(&data, av);
	init_philo(&data);
	create_philos(&data);
	destroy_philos(&data);
	clean_up(&data);
}
