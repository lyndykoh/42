/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:30:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:22:32 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stk_a;
	t_stack	stk_b;

	if (argc < 2)
	{
		return (0);
	}
	initstk(&stk_a, &stk_b);
	if (poocess_arg(argv, &stk_a) == 0)
		return (0);
	stk_a.fullsize = stk_a.size;
	ranking(&stk_a);
	if (check_sorted(&stk_a) != 1)
	{
		if (stk_a.fullsize < 7)
			sort_n(&stk_a, &stk_b);
		else
			radix_sort(&stk_a, &stk_b);
	}
	free_stack(&stk_a);
	free_stack(&stk_b);
}
