/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 10:51:31 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/31 08:50:03 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_if_p(char *str, int index, t_list **stack_a, t_list **stack_b)
{
	if (str[index] == 'a')
		pa(stack_a, stack_b);
	else if (str[index] == 'b')
		pb(stack_a, stack_b);
	else
		return (0);
	return (2);
}

int	ft_if_s(char *str, int index, t_list **stack_a, t_list **stack_b)
{
	if (str[index] == 'a')
		sa(stack_a);
	else if (str[index] == 'b')
		sb(stack_b);
	else if (str[index] == 's')
		ss(stack_a, stack_b);
	else
		return (0);
	return (2);
}

int	ft_if_r(char *str, int index, t_list **stack_a, t_list **stack_b)
{
	if (str[index] == 'r' && str[index + 1] == 'a')
		return (rra(stack_a), 3);
	if (str[index] == 'r' && str[index + 1] == 'b')
		return (rrb(stack_b), 3);
	if (str[index] == 'r' && str[index + 1] == 'r')
		return (rrr(stack_a, stack_b), 3);
	if (str[index] == 'a')
		return (ra(stack_a), 2);
	if (str[index] == 'b')
		return (rb(stack_b), 2);
	if (str[index] == 'r' && (str[index + 1] == '\n' || str[index + 1] == '\0'))
		return (rr(stack_a, stack_b), 2);
	return (0);
}

int	ft_what_is(char *str, int index, t_list **stack_a, t_list **stack_b)
{
	if (str[index] == 'p')
		return (ft_if_p(str, index + 1, stack_a, stack_b));
	else if (str[index] == 's')
		return (ft_if_s(str, index + 1, stack_a, stack_b));
	else if (str[index] == 'r')
		return (ft_if_r(str, index + 1, stack_a, stack_b));
	return (0);
}

int	ft_sort_algo(t_list **stack_a, t_list **stack_b, char *str)
{
	int	i;
	int	check;
	int	len;

	i = 0;
	len = stack_len(*stack_a);
	while (str[i] != '\0')
	{
		check = 0;
		check = ft_what_is(str, i, stack_a, stack_b);
		if (check == 0)
		{
			ft_free_stack(*stack_a, 0);
			free(str);
			exit(ft_free_stack(*stack_b, 1));
		}
		i += check;
		++i;
	}
	if (ft_sort_checker(*stack_a, len) == 1)
		return (1);
	return (0);
}
