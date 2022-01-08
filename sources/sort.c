/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:22:50 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/08 15:44:34 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_2_3(t_container *a, t_container *b)
{
	if (a->size == 2)
	{
		ft_swap_elements(a, b, stack_a);
		return ;
	}
	if (a->top->pos == 3)
	{
		ft_rotate_stack(a, b, stack_a);
		if (a->top->pos == 2)
			ft_swap_elements(a, b, stack_a);
	}
	else if (a->top->pos == 2)
	{
		if (a->bot->pos == 1)
			ft_reverse_stack(a, b, stack_a);
		else
			ft_swap_elements(a, b, stack_a);
	}
	else if (a->top->pos == 1 && a->bot->pos == 2)
	{
		ft_reverse_stack(a, b, stack_a);
		ft_swap_elements(a, b, stack_a);
	}
}

void	ft_sort_4_5_c(t_container *a, t_container *b)
{
	if (a->top->pos > a->top->next->pos || b->top->pos < b->bot->pos)
	{
		if (a->top->pos > a->top->next->pos && b->top->pos < b->bot->pos)
			ft_swap_elements(a, b, both_stacks);
		else if (a->top->pos > a->top->next->pos)
			ft_swap_elements(a, b, stack_a);
		else
			ft_swap_elements(a, b, stack_b);
	}
	while (ft_is_empty_stack(b) == false)
		ft_push_stack(b, a, stack_a);
}

void	ft_sort_4_5_b(t_container *a, t_container *b, t_tier *rank)
{
	if (a->bot->pos != rank->low_tier)
	{
		if (a->top->pos == rank->low_tier)
		{
			if (b->top->pos < b->bot->pos)
				ft_rotate_stack(a, b, both_stacks);
			else
				ft_rotate_stack(a, b, stack_a);
		}
		else
		{
			if (b->top->pos < b->bot->pos)
				ft_reverse_stack(a, b, both_stacks);
			else
				ft_reverse_stack(a, b, stack_a);
		}	
	}
	ft_sort_4_5_c(a, b);
}

void	ft_sort_4_5(t_container *a, t_container *b)
{
	t_tier	*rank;
	size_t	top_tier_element;
	size_t	i;

	i = 0;
	rank = ft_set_tier_info(a);
	while (i < rank->mid_tier)
	{
		top_tier_element = ft_scan_top_tier_elements(a, rank);
		if (top_tier_element <= rank->mid_tier)
			while (top_tier_element-- > 0)
				ft_rotate_stack(a, b, stack_a);
		else if (a->bot->pos <= rank->mid_tier)
			ft_reverse_stack(a, b, stack_a);
		else
			while (top_tier_element++ + i <= a->size)
				ft_reverse_stack(a, b, stack_a);
		ft_push_stack(a, b, stack_b);
		i++;
	}
	ft_sort_4_5_b(a, b, rank);
	free(rank);
}

void	ft_sort_algorithm_selection(t_container *a, t_container *b)
{
	if (ft_is_sorted(a) == true)
		return ;
	if (a->size <= 3)
		ft_sort_2_3(a, b);
	else if (a->size <= 5)
		ft_sort_4_5(a, b);
}
