/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:12:59 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/18 18:23:09 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	res;

	i = 0;
	signal = 0;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			signal++;
		}
		i++;
	}
	while ((int)nptr[i] >= 48 && (int)nptr[i] <= 57)
		res = res * 10 + ((int)nptr[i++] - 48);
	if (signal != 0)
		return (-res);
	else
		return (res);
}
