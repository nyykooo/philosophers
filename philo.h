/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:43:00 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/09 11:12:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
} t_fork;

typedef struct s_philo
{
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned long	t_think;
	unsigned long	t_last_meal;
	long			amount_eat;
	int				name;
	bool			is_awake;
	bool			stop;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		mind;
	pthread_mutex_t	body;
	struct s_table	*table;
} t_philo;

typedef struct s_table
{
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned int	n_philo;
	bool			all_alive;
	bool			all_eaten;
	long			start;
	int				amount_eat;
	pthread_mutex_t	may_we;
	pthread_mutex_t	print_message;
	t_philo			*philo;
	t_fork			*fork;
} t_table;

// GENERAL
int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
long	ft_atol(const char *nbr);
void	ft_exit(t_table *table);

// PRINTING
void	print_message(char *message, t_philo *philo, unsigned long time);
void	death_eaten(t_table *table, int name);

// PHILOS/THREADS
void	create_philo(t_table *table);
void	*mind_hub(void *philosopher);

// FORKS/MUTEXES
void	create_fork(t_table *table);
void	check_forks(t_philo *philo, t_fork *left, t_fork *right);

// ACTIONS
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

// TIME
void	better_msleep(long delay_ms);
long	gettimeofday_ms(void);

#endif