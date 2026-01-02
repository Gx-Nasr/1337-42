/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:37:03 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/21 05:56:34 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}

int	ft_sort_checker(t_list *list, int len)
{
	int		min;
	t_list	*check;

	check = list;
	if (stack_len(list) != len)
		return (0);
	while (list)
	{
		min = list->content;
		check = list;
		while (check)
		{
			if (min > check->content)
				return (0);
			check = check->next;
		}
		list = list->next;
	}
	return (1);
}
