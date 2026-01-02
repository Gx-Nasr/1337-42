/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:54:02 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/31 09:40:12 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_hp(t_list **stack_a, int what)
{
	if (what == 1)
	{
		if (ft_is_duplicat(*stack_a) == 1)
			exit(ft_free_stack(*stack_a, 1));
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
	t_list	*stack_b;
	t_list	*stack_a;
	char	*str;

	stack_b = NULL;
	stack_a = ft_lstnew();
	ft_main_hp(ac, av, stack_a);
	ft_hp(&stack_a, 1);
	str = ft_input();
	if (ft_sort_algo(&stack_a, &stack_b, str))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(stack_a, 0);
	ft_free_stack(stack_b, 0);
	free(str);
	return (0);
}
