/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:01:55 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/16 22:25:26 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("number of arguments is incorrect\n", 2);
	if (flag == 2)
		ft_putstr_fd("the arguments should be numbers\n", 2);
	if (flag == 3)
		ft_putstr_fd("the arguments should be integers\n", 2);
}

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		print_error(1);
		return (0);
	}
	if (!verify_num(ac, av))
	{
		print_error(2);
		return (0);
	}
	if (!verify_sign(ac, av))
	{
		print_error(3);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	data;

	memset(&data, 0, sizeof(t_philo));
	if (!check_args(ac, av))
	{
		return (1);
	}
	printf("philo ok\n");
}
