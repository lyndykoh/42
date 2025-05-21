/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:13:44 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:15:40 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_stack *stk)
{
	t_node	*temp;
	t_node	*temp_next;
	int		i;

	i = 0;
	temp = stk->head;
	while (i++ < stk->size)
	{
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
	stk->fullsize = 0;
	stk->size = 0;
	stk->head = NULL;
}
