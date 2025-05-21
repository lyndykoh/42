/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:48:10 by lkoh              #+#    #+#             */
/*   Updated: 2024/12/02 14:40:53 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mummum(int fork1, int fork2, t_philo *philo)
{
	if (philo->data->philono == 1)
	{
		pthread_mutex_lock(&(philo->data->forks[fork1]));
		printshit(philo, "has taken a fork", curr_time());
		pthread_mutex_unlock(&(philo->data->forks[fork1]));
		usleep(1100 * philo->data->t2die);
		return (1);
	}
	pthread_mutex_lock(&(philo->data->forks[fork1]));
	printshit(philo, "has taken a fork", curr_time());
	pthread_mutex_lock(&(philo->data->forks[fork2]));
	printshit(philo, "has taken a fork", curr_time());
	pthread_mutex_lock(&philo->data->checkmtx);
	philo->lastmeal = (long long)curr_time();
	philo->lastmeal2 = philo->lastmeal;
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->checkmtx);
	printshit(philo, "is eating", curr_time());
	ft_usleep2(philo->data->t2eat, philo->lastmeal2);
	pthread_mutex_unlock(&(philo->data->forks[fork1]));
	pthread_mutex_unlock(&(philo->data->forks[fork2]));
	orhorhtime(philo);
	return (0);
}

void	orhorhtime(t_philo *philo)
{
	printshit(philo, "is sleeping", curr_time());
	ft_usleep2(philo->data->t2sleep, philo->lastmeal2 + philo->data->t2eat);
	printshit(philo, "is thinking", curr_time());
	if (philo->id % 2 == 0)
	{
		usleep(2500);
	}
}

void	hungrydieme(t_philo *philo)
{
	long long	val;

	pthread_mutex_lock(&philo->data->checkmtx);
	val = curr_time();
	if ((val > philo->lastmeal + philo->data->t2die) && !philo->state)
	{
		printshit(philo, "died", curr_time());
		pthread_mutex_lock(&philo->data->write_lock);
		philo->data->stop_sim = 1;
		pthread_mutex_unlock(&philo->data->write_lock);
	}
	if (philo->data->finished == philo->data->philono)
	{
		pthread_mutex_lock(&philo->data->write_lock);
		philo->data->stop_sim = 1;
		pthread_mutex_unlock(&philo->data->write_lock);
	}
	pthread_mutex_unlock(&philo->data->checkmtx);
}
