/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:02:10 by hes-saou          #+#    #+#             */
/*   Updated: 2025/05/22 01:13:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct s_data;

typedef struct s_philosopher
{
	int				id;
	pthread_t		*thread;
	long long		last_time_eat;
	int				meals_eaten;
	struct s_data	*data;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philosopher;

typedef struct s_data
{
	int				num_philo;
	int				someone_died;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_must_eat;
	long			start_time;
	pthread_mutex_t print_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death_check;
	t_philosopher	*philos;
}					t_data;

/*utils functions*/
int					ft_isdigit(char *str);
void				print_error(int flag);
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(char *nptr);
int					verify_num(int ac, char **av);
int					verify_sign(int ac, char **av);
int					check_args(int ac, char **av);
long long			get_time_now(t_data *data);
void				init_args(t_data *data, char **av);
void				init_philo(t_data *data);
void				clean_up(t_data *data);



void	create_philos(t_data *data);
void	destroy_philos(t_data *data);
#endif