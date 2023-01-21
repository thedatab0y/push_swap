/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:47:54 by busmanov          #+#    #+#             */
/*   Updated: 2023/01/21 14:35:44 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returns the next minimum stack value
static t_node	*ft_get_nxt_min(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->number < min->number))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

// Assign their index to the nodes of the stack during initialization
//for radix
void	ft_index_stack(t_node **stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = ft_get_nxt_min(stack);
	while (head)
	{
		head->index = index++;
		head = ft_get_nxt_min(stack);
	}
}

// Dispatch to the optimal algo for the entered size (<5)
void	ft_simple_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (stack_is_sorted(stack_a) || ft_stack_size(*stack_a) == 0
		|| ft_stack_size(*stack_a) == 1)
		return ;
	size = ft_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort_three_nums(stack_a);
	else if (size == 4)
		ft_sort_four_nums(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five_nums(stack_a, stack_b);
}

// Radix sort of values by binary indexing
//In each iteration of the inner loop, the function checks the value of the
// i-th digit of the current element's index by using bitwise operator. If the 
//value is 1, the function calls the "ra" function to rotate the stack, otherwise 
//it calls the "pb" function to push the element onto the second stack.
void	ft_radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;
//second stack is for temporary usage
	i = 0;
	size = ft_stack_size(*stack_a);
	while (!stack_is_sorted(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}//After the inner loop, the function enters another loop that 
		while (ft_stack_size(*stack_b) != 0)//continues until the second stack is empty, using the "pa" function
			pa(stack_b, stack_a);//to move elements back onto the first stack.
		i++;//Finally, the "i" variable is incremented, and the process is repeated until the stack is sorted.
	}
}
