/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:20:34 by busmanov          #+#    #+#             */
/*   Updated: 2023/01/20 19:57:49 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;//next for the next node
}				t_node;

t_node	*ft_make_node(int number);
t_node	*get_last_node(t_node *head);//head is the first element
int		ft_stack_size(t_node *head);
void	ft_add_node_front(t_node **stack, t_node *new_node);
void	ft_add_node_back(t_node **stack, t_node *new_node);
void	ft_init_stack(t_node **stack, int argc, char **argv);
int		stack_is_sorted(t_node **stack);
int		get_distance_node(t_node **stack, int index);
void	s_free(t_node **stack);
void	ft_error_msg(char *msg);
void	ft_free(char **str);
void	ft_check_argums(int argc, char **argv);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

void	ft_push(t_node **stack_from, t_node **stack_dst);
void	ft_swap(t_node **stack);
void	ft_rotate(t_node **stack);
void	ft_reverse_rotate(t_node **stack);

int		ft_min(t_node **stack, int number);
void	ft_sort_three_nums(t_node **stack_a);
void	ft_sort_four_nums(t_node **stack_a, t_node **stack_b);
void	ft_sort_five_nums(t_node **stack_a, t_node **stack_b);

void	ft_radix_sort(t_node **stack_a, t_node **stack_b);
void	ft_simple_sort(t_node **stack_a, t_node **stack_b);
void	ft_index_stack(t_node **stack);

#endif