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
