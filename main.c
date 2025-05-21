/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:01:55 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/21 16:20:52 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos)
		free(data->philos);
	if (data->forks)
	{
		// while (i < data->num_philo)
		// {
		// 	pthread_mutex_destroy(&data->forks[i]);
		// 	i++;
		// }
	free(data->forks);
	}
		
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
