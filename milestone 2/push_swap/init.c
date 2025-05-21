/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:11:53 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:52:28 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initstk(t_stack *stk_a, t_stack *stk_b)
{
	stk_a->fullsize = 0;
	stk_a->size = 0;
	stk_a->head = NULL;
	stk_b->size = 0;
	stk_b->head = NULL;
}

int	poocess_in(char **temp, t_stack *stk_a)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (temp[i])
	{
		if (valid_integer(temp[i]) == 1)
		{
			new_node = malloc(sizeof(t_node));
			new_node->value = ft_atol(temp[i]);
			new_node->next = NULL;
			if ((new_node->value > INT_MAX) || (new_node->value < INT_MIN))
				return (free(new_node), -1);
			else if (add_node(new_node, stk_a) == -1)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (1);
}

int	poocess_arg(char **argv, t_stack *stk_a)
{
	int		i;
	char	**temp;

	i = 1;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ');
		if (temp == NULL)
			return (0);
		if (poocess_in(temp, stk_a) == -1)
			return (ft_printf("Error\n"), ft_free_split(temp),
				free_stack(stk_a), 0);
		if (temp[0] == NULL)
		{
			ft_free_split(temp);
			return (0);
		}
		i++;
		ft_free_split(temp);
	}
	return (1);
}

void	ranking(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	int		j;

	i = 0;
	if (!stack || !stack->head)
		return ;
	current = stack->head;
	while (i < stack->size)
	{
		current->rank = 0;
		compare = stack->head;
		j = 0;
		while (j < stack->size)
		{
			if (current->value > compare->value)
				current->rank++;
			compare = compare->next;
			j++;
		}
		current->base3 = to_base_3(current->rank);
		current = current->next;
		i++;
	}
}

int	add_node(t_node *new_node, t_stack *stk)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stk->head;
	while ((++i <= stk->size) && (i > 0))
	{
		if (temp->value == new_node->value)
			i = -2;
		temp = temp->next;
	}
	if (stk->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stk->head = new_node;
	}
	else
	{
		new_node->next = stk->head;
		new_node->prev = stk->head->prev;
		(stk->head->prev)->next = new_node;
		(stk->head)->prev = new_node;
	}
	return (stk->size++, i);
}
