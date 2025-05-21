/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:55:49 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/28 21:59:19 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->checkmtx);
	philo->lastmeal = philo->data->start;
	philo->lastmeal2 = philo->data->start;
	pthread_mutex_unlock(&philo->data->checkmtx);
	if (philo->id % 2 == 0)
		usleep(5000);
	while (1)
	{
		if (philo->id % 2 == 0)
			mummum(philo->left, philo->right, philo);
		else if (philo->id == philo->data->philono)
		{
			if (mummum(philo->left, philo->right, philo) == 1)
				break ;
		}
		else
			mummum(philo->right, philo->left, philo);
		if (exitcheck(philo) == -1)
			break ;
	}
	return (NULL);
}

void	*monitoring_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->checkmtx);
	pthread_mutex_unlock(&data->checkmtx);
	usleep(10000);
	while (1)
	{
		i = 0;
		while (i < data->philono)
		{
			hungrydieme(&(data->philos[i]));
			i++;
		}
		pthread_mutex_lock(&data->checkmtx);
		if (data->stop_sim == 1)
		{
			pthread_mutex_unlock(&data->checkmtx);
			break ;
		}
		pthread_mutex_unlock(&data->checkmtx);
	}
	return (NULL);
}
