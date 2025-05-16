/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:02:10 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/16 22:25:47 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> //////////////to be deleted later
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_philo_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_must_eat;
}		t_philo;

/*utils functions*/
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *nptr);
int		verify_num(int ac, char **av);
int		verify_sign(int ac, char **av);

#endif