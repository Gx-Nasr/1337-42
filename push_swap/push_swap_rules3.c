/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:34:30 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/21 05:56:34 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int print)
{
	int	tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
		if (print)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b, int print)
{
	int	tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp;
		if (print)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_b, t_list **stack_a)
{
	if ((*stack_b && (*stack_b)->next) && *stack_a && (*stack_a)->next)
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		write(1, "ss\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b, 0);
	ra(stack_a, 0);
	write(1, "rr\n", 3);
}

void	rrr(t_list **stack_b, t_list **stack_a)
{
	rrb(stack_b, 0);
	rra(stack_a, 0);
	write(1, "rrr\n", 4);
}
