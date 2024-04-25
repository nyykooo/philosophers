/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:18:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/24 17:27:40 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_fork	init_fork(t_table *table, int i)
{
	t_fork *fork;

	fork = malloc(sizeof(t_fork));
	fork->taken = false;
	fork->id = i + 1;
	if (pthread_mutex_init(&table->fork[i].fork, NULL) != 0)
		write(2, "invalid input\n", 15);//ft_error("pthread create\n", table);
	return (*fork);
}

void	create_fork(t_table *table)
{
	int	i;

	i = 0;
	table->fork = malloc(sizeof(t_fork)*table->n_philo);
	while (i <= (int)table->n_philo - 1)
	{
		table->fork[i] = init_fork(table, i);
		i++;
	}
}

bool	check_forks(t_fork *left, t_fork *right)
{
	if (!left->taken && !right->taken)
	{
		pthread_mutex_lock(&left->fork);
		left->taken = true;
		pthread_mutex_lock(&right->fork);
		right->taken = true;
		return (true);
	}
	else
		return (false);
}
