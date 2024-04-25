/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:37:24 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/18 18:23:18 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_atol(const char *nbr)
{
	long	res;
	int		signal;

	res = 0;
	signal = 1;
	if (*nbr == 45)
	{
		signal *= (-1);
		nbr++;
	}
	else if (*nbr == 43)
		nbr++;
	while (*nbr >= 48 && *nbr <= 57)
		res = res * 10 + (*nbr++ - 48);
	return (res * signal);
}
