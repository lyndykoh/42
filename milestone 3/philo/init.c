/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:11:53 by lkoh              #+#    #+#             */
/*   Updated: 2024/12/02 14:59:26 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initphilo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * (data->philono));
	if (!data->philos)
		return (-1);
	while (i < data->philono)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left = (i + 1) % data->philono;
		data->philos[i].right = i;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		data->philos[i].state = 0;
		i++;
	}
	return (0);
}

int	initforks(t_data *data)
{
	int	i;

	i = 0;
	if (data->philono <= 0)
	{
		return (-1);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philono));
	if (!data->forks)
		return (-1);
	while (i < data->philono)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	initmonitoring(t_data *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->checkmtx, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		return (-1);
	}
	return (0);
}

int	initdata(t_data *data, char **argv)
{
	data->philono = inputcheck_nbr(argv[1]);
	data->t2die = inputcheck_nbr(argv[2]);
	data->t2eat = inputcheck_nbr(argv[3]);
	data->t2sleep = inputcheck_nbr(argv[4]);
	if (argv[5])
	{
		if (inputcheck_nbr(argv[5]) <= 0)
			return (-1);
		data->n2eat = inputcheck_nbr(argv[5]);
	}
	else
		data->n2eat = -1;
	data->finished = 0;
	data->start = 0;
	data->state = 0;
	data->stop_sim = 0;
	data->monitoring = 0;
	data->forks = NULL;
	if ((data->philono <= 0) || (data->t2die <= 0) || (data->t2eat <= 0)
		|| (data->t2sleep <= 0))
		return (-1);
	return (0);
}
