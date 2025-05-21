/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:01:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:09:44 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->head->rank;
	mid = stack->head->next->rank;
	bot = stack->head->next->next->rank;
	if (check_sorted(stack) == 1)
		return ;
	if ((mid > top) && (top > bot))
		return (rra(stack));
	if ((mid > top) && (top < bot))
		return (rra(stack), sa(stack));
	if (bot > top)
		return (sa(stack));
	if (mid > bot)
	{
		sa(stack);
		rra(stack);
	}
	else
		ra(stack);
}

void	movehelper(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (i <= stack_a->size / 2)
	{
		while (i-- > 0)
			ra(stack_a);
	}
	else
	{
		while ((stack_a->size - i++) > 0)
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}

t_node	*move_to_a(t_stack *stack_a, t_stack *stack_b, int b_top, int j)
{
	t_node	*temp;
	int		i;

	temp = stack_a->head;
	while (++j <= stack_b->size)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (temp->rank == (b_top + j) % stack_a->fullsize)
			{
				movehelper(stack_a, stack_b, i);
				return (0);
			}
			temp = temp->next;
			i++;
		}
	}
	return (0);
}

t_node	*move_0_top(t_stack *stack_a, int i)
{
	t_node	*temp;

	temp = stack_a->head;
	while (i < stack_a->size)
	{
		if (temp->rank == 0)
		{
			if (i <= stack_a->size / 2)
			{
				while (i-- > 0)
					ra(stack_a);
			}
			else
			{
				while ((stack_a->size - i++) > 0)
					rra(stack_a);
			}
			break ;
		}
		temp = temp->next;
		i++;
	}
	return (0);
}

void	sort_n(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sorted(stack_a) == 1)
		return ;
	while (stack_a->size > 3)
	{
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (stack_b->size > 0)
		move_to_a(stack_a, stack_b, stack_b->head->rank, 0);
	move_0_top(stack_a, 0);
}
