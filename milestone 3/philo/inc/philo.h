/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:43:16 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/24 17:26:19 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define PINKT "\001\033[38;2;255;157;193m\002"
# define PINKT "\033[94m"
# define RESET "\001\033[0m\002"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					left;
	int					right;
	int					eat_count;
	long long			lastmeal;
	long long			lastmeal2;
	long long			ctime;
	t_data				*data;
	int					state;
	pthread_t			thread;
}						t_philo;

typedef struct s_data
{
	int					philono;
	int					t2die;
	int					t2eat;
	int					t2sleep;
	int					n2eat;
	int					finished;
	long long			start;
	int					*state;
	int					stop_sim;
	pthread_t			monitoring;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		checkmtx;
	t_philo				*philos;
}						t_data;

// init
int						initphilo(t_data *data);
int						initforks(t_data *data);
int						initmonitoring(t_data *data);
int						initdata(t_data *data, char **argv);

// time
size_t					curr_time(void);
long long				get_ctime(t_philo *philo, long long c_time);
void					p_print(t_philo *philo, char *str, long long c_time);

// free
void					free_all(t_data *data);

// threads
int						philo_thread(t_data *data);
int						exitcheck(t_philo *philo);

// routine
void					*start_routine(void *arg);
void					*monitoring_routine(void *arg);

// actions
int						mummum(int fork1, int fork2, t_philo *philo);
void					orhorhtime(t_philo *philo);
void					hungrydieme(t_philo *philo);

// others
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
int						inputcheck_nbr(char *shit);

// helper
void					printshit(t_philo *philo, char *action,
							long long c_time);
void					wmutex(int *one, int two, pthread_mutex_t *thread);

int						ft_usleep2(size_t milliseconds, long long start);

#endif