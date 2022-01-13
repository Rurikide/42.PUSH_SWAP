/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcomplex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:42:54 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/13 14:32:03 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_100_b(t_container *a, t_container *b, t_tier *rank)
{
	while (b->size != rank->mid_tier)
	{
		if (a->top->pos <= rank->mid_tier)
			ft_push_stack(a, b, stack_b);
		else if (a->top->next->pos <= rank->mid_tier)
		{
			ft_rotate_stack(a, b, stack_a);
			ft_push_stack(a, b, stack_b);
		}
		else if (a->bot->pos <= rank->mid_tier)
		{
			ft_reverse_stack(a, b, stack_a);
			ft_push_stack(a, b, stack_b);
		}
		else
			ft_rotate_stack(a, b, stack_a);
	}
	ft_sort_100_c(a, b, rank);
}

void	ft_sort_100_c(t_container *a, t_container *b, t_tier *rank)
{
	while (b->size != rank->low_tier - rank->mid_tier / 2)
	{
		if (a->top->pos <= rank->low_tier - rank->mid_tier / 2)
			ft_push_stack(a, b, stack_b);
		else if (a->top->next->pos <= rank->low_tier - rank->mid_tier / 2)
		{
			ft_rotate_stack(a, b, stack_a);
			ft_push_stack(a, b, stack_b);
		}
		else if (a->bot->pos <= rank->low_tier - rank->mid_tier / 2)
		{
			ft_reverse_stack(a, b, stack_a);
			ft_push_stack(a, b, stack_b);
		}
		else
			ft_rotate_stack(a, b, stack_a);
	}
	ft_sort_100_d(a, b, rank);
}

void	ft_sort_100_d(t_container *a, t_container *b, t_tier *rank)
{
	size_t	parcour;
	size_t	i;

	i = 1;
	while (a->size != 1)
	{
		parcour = ft_find_element(a, rank->low_tier - rank->mid_tier / 2 + i);
		while (true)
		{
			if (parcour < a->size / 2 + 1)
				while (parcour--)
					ft_rotate_stack(a, b, stack_a);
			else
				while ((rank->low_tier - rank->mid_tier / 2 + i) != a->top->pos)
					ft_reverse_stack(a, b, stack_a);
			ft_push_stack(a, b, stack_b);
			i++;
			break ;
		}
	}
	ft_sort_100_e(a, b, rank);
}

void	ft_sort_100_e(t_container *a, t_container *b, t_tier *rank)
{
	size_t	parcour;
	size_t	i;

	while (a->size != rank->low_tier / 4)
		ft_push_stack(b, a, stack_a);
	i = rank->low_tier - rank->mid_tier / 2 ;
	while (a->size != rank->mid_tier)
	{
		parcour = ft_find_element(b, i);
		while (true)
		{
			if (parcour < b->size / 2 + 2)
				while (parcour--)
					ft_rotate_stack(a, b, stack_b);
			else
				while (i != b->top->pos)
					ft_reverse_stack(a, b, stack_b);
			ft_push_stack(b, a, stack_a);
			i--;
			break ;
		}
	}
	ft_sort_100_f(a, b, rank);
}

void	ft_sort_100_f(t_container *a, t_container *b, t_tier *rank)
{
	size_t	parcour;
	size_t	i;

	i = rank->mid_tier;
	while (ft_is_empty_stack(b) == false)
	{
		parcour = ft_find_element(b, i);
		while (true)
		{
			if (parcour < b->size / 2 + 1)
				while (parcour--)
					ft_rotate_stack(a, b, stack_b);
			else
				while (i != b->top->pos)
					ft_reverse_stack(a, b, stack_b);
			ft_push_stack(b, a, stack_a);
			i--;
			break ;
		}
	}
}
