/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:48:52 by lkoh              #+#    #+#             */
/*   Updated: 2024/12/02 11:31:36 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->checkmtx);
	while (i < data->philono)
	{
		if (pthread_create(&data->philos[i].thread, NULL, start_routine,
				&data->philos[i]) != 0)
		{
			printf("ur philos not born\n");
		}
		i++;
	}
	if (pthread_create(&data->monitoring, NULL, monitoring_routine, data) != 0)
		printf("the class monitor died :/\n");
	data->start = curr_time();
	pthread_mutex_unlock(&data->checkmtx);
	i = -1;
	while (++i < data->philono)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(data->monitoring, NULL);
	return (0);
}

int	exitcheck(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->checkmtx);
	if (philo->data->n2eat != -1)
	{
		if (philo->eat_count >= philo->data->n2eat)
		{
			philo->data->finished++;
			philo->state = 1;
			pthread_mutex_unlock(&philo->data->checkmtx);
			return (-1);
		}
	}
	if (philo->data->stop_sim == 1)
	{
		pthread_mutex_unlock(&philo->data->checkmtx);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->checkmtx);
	return (0);
}
