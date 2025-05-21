/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:29:22 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/30 16:06:56 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (!stack || !stack->head || stack->size <= 1)
		return ;
	stack->head = stack->head->next;
}

void	ra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || stack_a->size <= 1)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->head || stack_b->size <= 1)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
