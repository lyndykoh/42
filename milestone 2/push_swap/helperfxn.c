/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfxn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:40 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:26:45 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->head;
	while ((++i <= stack->size) && (i > 0))
	{
		printf("stack a node %d\tvalue  %ld\trank %d\t base3 %d\n", i,
			temp->value, temp->rank, temp->base3);
		temp = temp->next;
	}
}

void	print2stack(t_stack *sa, t_stack *sb)
{
	printf("Stack A, size = %d\n", sa->size);
	printstack(sa);
	printf("Stack B, size = %d\n", sb->size);
	printstack(sb);
}

int	count_base3_digits(unsigned long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		digits++;
		n /= 3;
	}
	return (digits);
}

long	to_base_3(unsigned long n)
{
	long	result;
	long	multiplier;

	result = 0;
	multiplier = 1;
	while (n > 0)
	{
		result += (n % 3) * multiplier;
		multiplier *= 10;
		n /= 3;
	}
	return (result);
}

int	base_3(unsigned long n, int pos)
{
	if (pos == 0)
		return (n % 3);
	else
		return (base_3(n / 3, pos - 1));
}
