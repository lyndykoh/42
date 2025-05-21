/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:24:59 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/28 21:50:14 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printshit(t_philo *philo, char *action, long long c_time)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (!philo->data->stop_sim)
	{
		printf("%s%08lld%s %d %s\n", PINKT, c_time - philo->data->start, RESET,
			philo->id, action);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	wmutex(int *one, int two, pthread_mutex_t *thread)
{
	pthread_mutex_lock(thread);
	*one = two;
	pthread_mutex_unlock(thread);
}

int	ft_usleep2(size_t milliseconds, long long start)
{
	struct timeval	current;
	size_t			elapsed;

	while (1)
	{
		usleep(100);
		if (gettimeofday(&current, NULL) == -1)
		{
			write(2, "gettimeofday() error\n", 22);
			return (-1);
		}
		elapsed = (current.tv_sec) * 1000 + (current.tv_usec) / 1000 - start;
		if (elapsed >= milliseconds)
			break ;
	}
	return (0);
}
