/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:54:17 by lkoh              #+#    #+#             */
/*   Updated: 2024/12/02 15:08:11 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	inputcheck_nbr(char *shit)
{
	int	i;

	i = 0;
	while (shit[i])
	{
		if (!(shit[i] >= '0' && shit[i] <= '9'))
			return (-1);
		i++;
	}
	return (ft_atoi(shit));
}
