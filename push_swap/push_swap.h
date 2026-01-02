/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:57:09 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/22 12:53:19 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*      STRUCT LIST     */

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

/*      PUSH_SWAP_C     */

void				ft_index_hp(t_list *stack, int nb);
int					ft_index_checker(t_list *stack);
void				ft_hp(t_list **stack_a, int what);
void				ft_main_hp(int ac, char **av, t_list *stack_a);

/*      PUSH_SWAP_UTILS_C       */

int					ft_is_duplicat(t_list *stack);
int					ft_free_stack(t_list *stack, int print);
int					ft_numbers(char *str, int i);
int					ft_str_atoi(char *str, int *i, t_list *stack_a);
int					ft_atoi(char *str, t_list *stack_a);

/*      PUSH_SWAP_RULES1_C       */

t_list				*ft_lstnew(void);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);

/*      PUSH_SWAP_RULES2_C       */

void				ra(t_list **stack_a, int print);
void				rb(t_list **stack_b, int print);
void				rra(t_list **stack_a, int print);
void				rrb(t_list **stack_b, int print);

/*      PUSH_SWAP_RULES3_C       */

void				sa(t_list **stack_a, int print);
void				sb(t_list **stack_b, int print);
void				ss(t_list **stack_b, t_list **stack_a);
void				rr(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_b, t_list **stack_a);

/*      HARD_SORT_C     */

void				ft_sort_tree(t_list **stack_a, int nb);
void				ft_sort_five(t_list **stack_a, t_list **stack_b);
void				push_swap(t_list **stack_a, t_list **stack_b);

/*      SORTING_UTILS_C     */

int					stack_len(t_list *stack);
int					ft_sort_checker(t_list *list, int len);

/*      SORTING_C       */

int					ft_is_pb(t_list *stack, int min, int max);
int					get_min_pos(t_list *stack);
int					get_max_pos(t_list *stack);
void				sort_b_to_a(t_list **stack_a, t_list **stack_b);
void				ft_sort_algo(t_list **stack_a, t_list **stack_b);

#endif
