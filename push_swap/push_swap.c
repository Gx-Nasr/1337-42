/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:54:02 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/31 08:51:32 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_hp(t_list *stack, int nb)
{
	t_list	*small;
	int		min;

	small = NULL;
	while (stack)
	{
		if (stack->index == -1 && (small == NULL || min > stack->content))
		{
			min = stack->content;
			small = stack;
		}
		stack = stack->next;
	}
	if (small)
		small->index = nb;
}

int	ft_index_checker(t_list *stack)
{
	while (stack)
	{
		if (stack->index == -1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_hp(t_list **stack_a, int what)
{
	t_list	*stack_b;
	int		nb;

	if (what == 1)
	{
		stack_b = NULL;
		nb = 0;
		while (ft_index_checker(*stack_a))
		{
			ft_index_hp(*stack_a, nb);
			++nb;
		}
		if (ft_is_duplicat(*stack_a) == 1)
			exit(ft_free_stack(*stack_a, 1));
		push_swap(stack_a, &stack_b);
		ft_free_stack(*stack_a, 0);
	}
	else if (what == 0)
	{
		(*stack_a)->next = ft_lstnew();
		*stack_a = (*stack_a)->next;
		(*stack_a)->next = NULL;
	}
}

void	ft_main_hp(int ac, char **av, t_list *stack_a)
{
	int		i;
	int		index;
	t_list	*head;

	head = stack_a;
	i = 1;
	while (i < ac)
	{
		index = 0;
		if (ft_numbers(av[i], index) == 0)
			exit(ft_free_stack(head, 1));
		if (ft_numbers(av[i], index) > 1)
		{
			while (ft_numbers(av[i], index) > 0)
			{
				stack_a->content = ft_str_atoi(av[i], &index, head);
				if (ft_numbers(av[i], index) > 0)
					ft_hp(&stack_a, 0);
			}
		}
		else
			stack_a->content = ft_atoi(av[i], head);
		if (++i < ac)
			ft_hp(&stack_a, 0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	stack_a = ft_lstnew();
	ft_main_hp(ac, av, stack_a);
	ft_hp(&stack_a, 1);
	return (0);
}
