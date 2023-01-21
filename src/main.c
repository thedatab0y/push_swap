/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:47:14 by busmanov          #+#    #+#             */
/*   Updated: 2023/01/20 19:46:48 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Choose the algo according to the size to sort
static void	ft_sort_stack(t_node **stack_a, t_node **stack_b)
{
	if (ft_stack_size(*stack_a) <= 5)
		ft_simple_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		return (0);
	ft_check_argums(argc, argv);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_init_stack(stack_a, argc, argv);
	if (stack_is_sorted(stack_a))
	{
		s_free(stack_a);
		s_free(stack_b);
		return (0);
	}
	ft_sort_stack(stack_a, stack_b);
	s_free(stack_a);
	s_free(stack_b);
	return (0);
}
