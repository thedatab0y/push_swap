/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:47:51 by busmanov          #+#    #+#             */
/*   Updated: 2023/01/20 19:55:23 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//perform push_swap operations
void	sa(t_node **stack_a)
{
	ft_swap(stack_a);//swap stack a
	ft_putendl_fd("sa", 1);//print 'sa'
}

void	sb(t_node **stack_b)
{
	ft_swap(stack_b);//swap stack b
	ft_putendl_fd("sb", 1);//print 'sb'
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return ;
	ft_swap(stack_a);//swap stack a
	ft_swap(stack_b);//swap stack b
	ft_putendl_fd("ss", 1);//print 'ss'
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);//print 'pa'
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);//print 'pb'
}
