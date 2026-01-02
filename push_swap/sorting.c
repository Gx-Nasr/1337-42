/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 10:51:31 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/22 14:00:21 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_pb(t_list *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_min_pos(t_list *stack)
{
	int	min;
	int	pos;
	int	i;

	min = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	get_max_pos(t_list *stack)
{
	int	max;
	int	pos;
	int	i;

	max = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	sort_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_pos;

	while (*stack_b)
	{
		size = stack_len(*stack_b);
		max_pos = get_max_pos(*stack_b);
		if (max_pos < size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b, 1);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b);
	}
}

void	ft_sort_algo(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	size_b;
	int	chunk;

	size = stack_len(*stack_a);
	if (size <= 100)
		chunk = 15;
	else if (size <= 500)
		chunk = 35;
	else
		chunk = 45;
	while (*stack_a)
	{
		size_b = stack_len(*stack_b);
		if ((*stack_a)->index <= size_b)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
		}
		else if ((*stack_a)->index < size_b + chunk)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}
	sort_b_to_a(stack_a, stack_b);
}
