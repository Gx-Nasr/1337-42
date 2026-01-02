/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:34:30 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/22 13:40:21 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_list **stack_a)
{
	int	tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
	}
}

void	sb(t_list **stack_b)
{
	int	tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp;
	}
}

void	ss(t_list **stack_b, t_list **stack_a)
{
	if ((*stack_b && (*stack_b)->next) && *stack_a && (*stack_a)->next)
	{
		sa(stack_a);
		sb(stack_b);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b);
	ra(stack_a);
}

void	rrr(t_list **stack_b, t_list **stack_a)
{
	rrb(stack_b);
	rra(stack_a);
}
