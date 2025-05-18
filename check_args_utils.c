/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:15:08 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/17 13:49:36 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verify_num(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isdigit(av[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	verify_sign(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
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
