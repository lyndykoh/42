/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:13:09 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/28 20:14:34 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 22);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	p_print(t_philo *philo, char *str, long long c_time)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (!philo->data->stop_sim)
	{
		printf("%08lld %d %s\n", c_time - philo->data->start, philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

long long	get_ctime(t_philo *philo, long long c_time)
{
	return (c_time - philo->data->start);
}
