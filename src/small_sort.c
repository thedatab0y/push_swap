/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:48:03 by busmanov          #+#    #+#             */
/*   Updated: 2023/01/20 19:52:35 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//It initializes a ptr "head" to the 
//1st element of the stack, and an int 
//"min_index" to the "index" value of the 1st element.
//the function then iterates through the linked list, 
//starting with the 2nd element, and compares the "index" 
//value of each element to the current min "index" value.
 //If the "index" value of the current element is less than the 
 //current min "index" and it is not equal to the "number" 
//argument, then the "index" value of the current element becomes 
//the new min "index" value

int	ft_min(t_node **stack, int number)
{
	t_node	*head;
	int		min_index;

	head = *stack;
	min_index = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min_index) && head->index != number)
			min_index = head->index;
	}
	return (min_index);
}

//sort three numbers
//It first checks if the 1st element is the min num 
//and the 2nd num is not the min element, in which case
//it calls function "ra" and "sa" and "rra" to sort the numbers.
//if both st and 2nd numbers are minimum number, 
//then it calls the funciton "sa" to sort.
//if 1st number is not the min, then it checks the 2nd num
//is min and calls "ra". Else, "sa" and "rra" functions
// to sort

void	ft_sort_three_nums(t_node **stack_a)
{
	if ((*stack_a)->index == ft_min(stack_a, -1)
		&& (*stack_a)->next->index != ft_min(stack_a, ft_min(stack_a, -1)))
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index == ft_min(stack_a, ft_min(stack_a, -1)))
	{
		if ((*stack_a)->next->index == ft_min(stack_a, -1))
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == ft_min(stack_a, -1))
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

//sort four numbers
//it first calls the function "get_distance_node" to 
//determine the distance between the 1st element of 
//"stack_a" and the min element of "stack_a"
// it needs the returned distance to decide which 
//rotation function to call(ra, rra) in order to move
//the min element to the top of the stack.
//next, it checks if the stack is sorted with
//stack_is_sorted function. if sorted 


void	ft_sort_four_nums(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_node(stack_a, ft_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	ft_sort_three_nums(stack_a);
	pa(stack_b, stack_a);
}

//sort five numbers
void	ft_sort_five_nums(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_node(stack_a, ft_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	ft_sort_four_nums(stack_a, stack_b);
	pa(stack_b, stack_a);
}
