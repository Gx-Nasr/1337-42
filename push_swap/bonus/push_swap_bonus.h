/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:49:18 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/22 13:35:40 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

void				ft_hp(t_list **stack_a, int what);
void				ft_main_hp(int ac, char **av, t_list *stack_a);
t_list				*ft_lstnew(void);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_b, t_list **stack_a);
void				rr(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_b, t_list **stack_a);
int					ft_is_duplicat(t_list *stack);
int					ft_free_stack(t_list *stack, int print);
int					ft_numbers(char *str, int i);
int					ft_str_atoi(char *str, int *i, t_list *stack_a);
int					ft_atoi(char *str, t_list *stack_a);
int					ft_strlen(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_input(void);
int					ft_if_p(char *str, int index, t_list **stack_a,
						t_list **stack_b);
int					ft_if_s(char *str, int index, t_list **stack_a,
						t_list **stack_b);
int					ft_if_r(char *str, int index, t_list **stack_a,
						t_list **stack_b);
int					ft_what_is(char *str, int index, t_list **stack_a,
						t_list **stack_b);
int					ft_sort_algo(t_list **stack_a, t_list **stack_b, char *str);
int					stack_len(t_list *stack);
int					ft_sort_checker(t_list *list, int len);

#endif