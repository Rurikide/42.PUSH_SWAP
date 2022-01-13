/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcomplex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:42:54 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/12 23:13:01 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_count_binary_digit(size_t lowest_rank)
{
	size_t	counter;

	counter = 0;
	while (lowest_rank >> counter != 0)
		counter++;
	return (counter);
}

size_t	ft_find_element(t_container *a, size_t j)
{
	size_t		i;
	t_element	*scan;

	scan = a->top;
	i = 0;
	while (scan->pos != j)
	{
		scan = scan->next;
		i++;
	}
	return (i);
}

void	ft_sort_100(t_container *a, t_container *b)
{
	t_tier	*rank;
	size_t	parcour;
	size_t	i;
	size_t	j;

	i = 1;
	rank = ft_set_tier_info(a);
	while (i <= rank->mid_tier)
	{
		if (a->top->pos <= rank->mid_tier)
		{
			ft_push_stack(a, b, stack_b);
			i++;
		}
		else
			ft_rotate_stack(a, b, stack_a);
	}
	i = rank->mid_tier;
	j = rank->low_tier - rank->mid_tier / 2;
	while (i)
	{
		if (a->top->pos <= j)
			ft_push_stack(a, b, stack_b);
		else
			ft_rotate_stack(a, b, stack_a);
		i--;
	}
// // FIRSTIME 
	while (ft_is_empty_stack(a) == false)
	{
		j++;
		parcour = ft_find_element(a, j);
		while (true)
		{
			if (parcour < a->size / 2)
				while (parcour--)
					ft_rotate_stack(a, b, stack_a);
			else
			{
				parcour = a->size - parcour;
				while (parcour--)
					ft_reverse_stack(a, b, stack_a);
			}
			ft_push_stack(a, b, stack_b);
			break ;
		}
	}
	i = 0;
	while (i++ < rank->low_tier / 2)
		ft_push_stack(b, a, stack_a);
// SECOND TIME
	j = rank->mid_tier;
	while (ft_is_empty_stack(a) == false)
	{
		j++;
		parcour = ft_find_element(a, j);
		while (true)
		{
			if (parcour < a->size / 2)
				while (parcour--)
					ft_rotate_stack(a, b, stack_a);
			else
			{
				parcour = a->size - parcour;
				while (parcour--)
					ft_reverse_stack(a, b, stack_a);
			}
			ft_push_stack(a, b, stack_b);
			break ;
		}
	}
	i = 0;
	while (i++ < rank->low_tier / 2)
		ft_push_stack(b, a, stack_a);
// // THIRD TIME
	j = rank->mid_tier;
	while (j > 0)
	{
		parcour = ft_find_element(b, j);
		while (true)
		{
			if (parcour < b->size / 2)
			{
				while (parcour--)
					ft_rotate_stack(a, b, stack_b);
			}
			else
			{
				parcour = b->size - parcour;
				while (parcour--)
					ft_reverse_stack(a, b, stack_b);
			}
			ft_push_stack(b, a, stack_a);
			j--;
			break ;
		}
	}
	i = 0;
	while (i++ < 25)
		ft_push_stack(b, a, stack_a);
	free(rank);
}

void	ft_radix_sort(t_container *a, t_container *b)
{
	t_tier	*rank;
	size_t	i;
	size_t	j;
	size_t	binary_len;

	rank = ft_set_tier_info(a);
	i = -1;
	binary_len = ft_count_binary_digit(rank->low_tier);
	while (++i < binary_len)
	{
		j = 0;
		while (j++ < rank->low_tier)
		{
			if (((a->top->pos >> i) & 1) == 0)
				ft_push_stack(a, b, stack_b);
			else
				ft_rotate_stack(a, b, stack_a);
		}
		while (ft_is_empty_stack(b) == false)
			ft_push_stack(b, a, stack_a);
	}
	free(rank);
}
