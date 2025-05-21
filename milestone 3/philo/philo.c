/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:30:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/12/02 14:39:23 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("Hello brother.. what uw me to do?\n"), 0);
	if (initdata(&data, argv) == -1)
	{
		printf("Parameter errors!\n");
		return (-1);
	}
	if (initphilo(&data) == -1)
		return (-1);
	if (initforks(&data) == -1)
	{
		free_all(&data);
		return (-1);
	}
	initmonitoring(&data);
	philo_thread(&data);
	free_all(&data);
	return (1);
}
