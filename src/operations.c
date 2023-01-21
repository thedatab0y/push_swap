/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:39:47 by busmanov          #+#    #+#             */
/*   Updated: 2023/01/21 13:14:29 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}

void	ft_push(t_node **stack_from, t_node **stack_dst)
{
	t_node	*tmp;

	if (ft_stack_size(*stack_from) == 0)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	ft_add_node_front(stack_dst, tmp);
}

void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}
//perform rotation on the stack
void	ft_rotate(t_node **stack)
{//it creates two pointers 
	t_node	*tail;//one pointing to the current tail of the stack
	t_node	*head;//heading to the current head of the stack

	if (ft_stack_size(*stack) < 2)//checks if the stack has less than 2 elements
		return ;//returns nothing
	tail = get_last_node(*stack);//find the last element of the stack
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;//the next pointer of the current tail is set to point to the current head
	head->next = NULL;//the next pointer of the current head is set to NULL
}
//perform reverse rotation on the stack
//The function first checks if the stack has
//less than two elements, in that case the function returns without doing anything.
//Then it creates two pointers, one pointing to the current tail of the stack and another one pointing to the previous tail of the stack.
//Inside the while loop, it iterates through the elements of the stack, updating the "prev_tail" pointer to point to the next element until it reaches the second to last element of the stack.
//Once the "prev_tail" pointer points to the second to last element, the "tail" pointer is set to point to the last element.
//The next pointer of the second to last element is set to NULL, so that it is no longer pointing to the last element.
//The next pointer of the last element is set to the current head of the stack, so that the last element becomes the new head of the stack.
void	ft_reverse_rotate(t_node **stack)
{
	t_node	*prev_tail;
	t_node	*tail;

	if (ft_stack_size(*stack) < 2)
		return ;
	prev_tail = *stack;
	while (prev_tail->next->next)
		prev_tail = prev_tail->next;
	tail = prev_tail->next;
	prev_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}
