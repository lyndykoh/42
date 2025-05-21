/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:27:33 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/27 18:43:43 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getsrcnode(t_stack *src)
{
	t_node	*temp;

	if (!src || !src->head)
		return (NULL);
	temp = src->head;
	if (src->size == 1)
		src->head = NULL;
	else
	{
		src->head = temp->next;
		(src->head)->prev = temp->prev;
		(temp->prev)->next = src->head;
	}
	src->size--;
	return (temp);
}

void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	temp = getsrcnode(src);
	if (!dest->head)
	{
		dest->head = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	temp->next = dest->head;
	temp->prev = (dest->head)->prev;
	dest->head = temp;
	((dest->head)->next)->prev = dest->head;
	((dest->head)->prev)->next = dest->head;
	dest->size++;
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
