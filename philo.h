/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:43:00 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/25 15:40:50 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_fork
{
	bool			taken;
	int				id;
	pthread_mutex_t	fork;
} t_fork;

typedef struct s_philo
{
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned long	t_last_meal;
	int				amount_eat;
	int				name;
	bool			is_awake;
	t_fork			l_fork;
	t_fork			r_fork;
	pthread_t		mind;
	struct s_table	*table;
} t_philo;

typedef struct s_table
{
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned int	n_philo;
	int				amount_eat;
	pthread_mutex_t	may_we;
	pthread_mutex_t	print_message;
	struct timeval	start;
	t_philo			*philo;
	t_fork			*fork;
} t_table;

// GENERAL
int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
long	ft_atol(const char *nbr);
void	print_message(int	m_id, t_philo *philo);
void	ft_exit(char *message, t_table *table);

// PHILOS/THREADS
void	create_philo(t_table *table);
void	*mind_hub(void *philosopher);

// FORKS/MUTEXES
void	create_fork(t_table *table);
bool	check_forks(t_fork *left, t_fork *right);

// ACTIONS
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);


#endif