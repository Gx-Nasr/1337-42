/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:44:14 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/31 08:53:16 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicat(t_list *stack)
{
	t_list	*head1;
	t_list	*head2;
	int		dup;

	head1 = stack;
	while (head1)
	{
		dup = head1->content;
		head2 = head1->next;
		while (head2)
		{
			if (dup == head2->content)
				return (1);
			head2 = head2->next;
		}
		head1 = head1->next;
	}
	return (0);
}

int	ft_free_stack(t_list *stack, int print)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
	if (print == 1)
		write(1, "Error\n", 6);
	return (1);
}

int	ft_numbers(char *str, int i)
{
	int	numbers;

	numbers = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			++numbers;
		while (str[i] >= '0' && str[i] <= '9')
			++i;
		if (str[i] == '\0')
			break ;
		if ((str[i] > '9' || str[i] < '0') && (str[i] != ' ' && str[i] != '\0'
				&& str[i] != '-' && str[i] != '+'))
			return (0);
		++i;
	}
	return (numbers);
}

int	ft_str_atoi(char *str, int *i, t_list *stack_a)
{
	long	nb;
	int		type;

	nb = 0;
	type = 1;
	while (str[*i] == ' ' && str[*i] != '\0')
		++(*i);
	if (str[*i] == '-' || str[*i] == '+')
		if (str[(*i)++] == '-')
			type = -1;
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		exit (ft_free_stack(stack_a, 1));
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = (nb * 10) + str[*i] - '0';
		++(*i);
		if (nb * type > 2147483647 || nb * type < -2147483648)
			exit(ft_free_stack(stack_a, 1));
	}
	if ((str[*i] > '9' || str[*i] < '0') && (str[*i] != ' ' && str[*i] != '\0'))
		exit(ft_free_stack(stack_a, 1));
	return (nb * type);
}

int	ft_atoi(char *str, t_list *stack_a)
{
	long	nb;
	int		i;
	int		type;

	i = 0;
	nb = 0;
	type = 1;
	while (str[i] == ' ' && str[i] != '\0')
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			type = -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		exit (ft_free_stack(stack_a, 1));
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		++i;
		if (nb * type > 2147483647 || nb * type < -2147483648)
			exit(ft_free_stack(stack_a, 1));
	}
	if ((str[i] > '9' || str[i] < '0') && (str[i] != ' ' && str[i] != '\0'))
		exit(ft_free_stack(stack_a, 1));
	return (nb * type);
}
