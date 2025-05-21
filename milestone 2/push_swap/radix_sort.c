/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:40 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:21:13 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_nlr(t_stack *stack_a, t_stack *stack_b, int sf)
{
	int	i;
	int	startsize;

	i = 0;
	startsize = stack_a->size;
	while (i < startsize)
	{
		if (base_3(stack_a->head->rank, sf) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	startsize = stack_a->size;
	i = 0;
	while (i < startsize)
	{
		if (base_3(stack_a->head->rank, sf) == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	while (stack_a->size != 0)
		pb(stack_a, stack_b);
}

// mini optimisation
// if less than 161, which is 12222 in base 3, there is no 2 to push over.
// hence, only push over the 0, don't need to push over the 1.
// after that, return 0 to the stack a to complete
void	radix_nlr2(t_stack *stack_a, t_stack *stack_b, int sf)
{
	int	i;
	int	startsize;

	i = 0;
	startsize = stack_a->size;
	while (i < startsize)
	{
		if (base_3(stack_a->head->rank, sf) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	radix_nrl(t_stack *stack_a, t_stack *stack_b, int sf)
{
	int	i;
	int	startsize;

	i = 0;
	startsize = stack_b->size;
	while (i < startsize)
	{
		if (base_3(stack_b->head->rank, sf) == 2)
			pa(stack_b, stack_a);
		else
			rb(stack_b);
		i++;
	}
	startsize = stack_b->size;
	i = 0;
	while (i < startsize)
	{
		if (base_3(stack_b->head->rank, sf) == 1)
			pa(stack_b, stack_a);
		else
			rb(stack_b);
		i++;
	}
	while (stack_b->size != 0)
		pa(stack_b, stack_a);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	times;
	int	i;

	times = count_base3_digits(stack_a->fullsize - 1);
	i = 0;
	while (i < times)
	{
		if ((i == times - 1) && (i % 2 == 0) && stack_a->fullsize < 161)
		{
			radix_nlr2(stack_a, stack_b, i);
		}
		else if (stack_a->size <= 0)
			radix_nrl(stack_a, stack_b, i);
		else
			radix_nlr(stack_a, stack_b, i);
		i++;
	}
	if (i % 2 == 1)
	{
		while (stack_b->size > 0)
			pa(stack_b, stack_a);
	}
}
