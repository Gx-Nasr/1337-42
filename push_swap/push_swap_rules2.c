/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:31:54 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/21 05:56:34 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int print)
{
	t_list	*last;
	t_list	*head;

	if (*stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		while (last->next)
			last = last->next;
		head->next = NULL;
		last->next = head;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b, int print)
{
	t_list	*last;
	t_list	*head;

	if (*stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		while (last->next)
			last = last->next;
		head->next = NULL;
		last->next = head;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rra(t_list **stack_a, int print)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack_a;
	tmp2 = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		while (tmp1->next)
			tmp1 = tmp1->next;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		tmp1->next = *stack_a;
		*stack_a = tmp1;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b, int print)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack_b;
	tmp2 = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		while (tmp1->next)
			tmp1 = tmp1->next;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		tmp1->next = *stack_b;
		*stack_b = tmp1;
		if (print)
			write(1, "rrb\n", 4);
	}
}
