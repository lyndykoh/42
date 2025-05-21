/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:09:12 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/28 20:13:54 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks != NULL)
	{
		while (i < data->philono)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->checkmtx);
	if (data->philos != NULL)
		free(data->philos);
}
