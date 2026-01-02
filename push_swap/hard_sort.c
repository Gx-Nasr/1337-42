/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:32 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/22 13:20:51 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tree(t_list **stack_a, int nb)
{
	if ((*stack_a)->index == nb)
		ra(stack_a, 1);
	if ((*stack_a)->next->index == nb)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = 0;
	while (1)
	{
		if ((*stack_a)->index == 0)
		{
			pb(stack_a, stack_b);
			++count;
		}
		else
			ra(stack_a, 1);
		if (count == 1)
			break ;
	}
	ft_sort_tree(stack_a, 3);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = 0;
	while (1)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			pb(stack_a, stack_b);
			++count;
		}
		else
			ra(stack_a, 1);
		if (count == 2)
			break ;
	}
	ft_sort_tree(stack_a, 4);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = stack_len(*stack_a);
	if (ft_sort_checker(*stack_a, stack_size) == 1)
		exit(ft_free_stack(*stack_a, 0));
	else if (stack_size == 2)
		sa(stack_a, 1);
	else if (stack_size == 3)
		ft_sort_tree(stack_a, 2);
	else if (stack_size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (stack_size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_algo(stack_a, stack_b);
}
