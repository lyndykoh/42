/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:07:06 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:25:50 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_integer(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_sorted(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	while (i < stack->size - 1)
	{
		if (current->value > current->next->value)
		{
			return (0);
		}
		current = current->next;
		i++;
	}
	return (1);
}
