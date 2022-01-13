/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:37:16 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/13 13:50:33 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_100(t_container *a, t_container *b)
{
	t_tier	*rank;

	rank = ft_set_tier_info(a);
	while (b->size != rank->mid_tier / 2)
	{
		if (a->top->pos <= rank->mid_tier / 2)
			ft_push_stack(a, b, stack_b);
		else if (a->top->next->pos <= rank->mid_tier / 2)
		{
			ft_rotate_stack(a, b, stack_a);
			ft_push_stack(a, b, stack_b);
		}
		else if (a->bot->pos <= rank->mid_tier / 2)
		{
			ft_reverse_stack(a, b, stack_a);
			ft_push_stack(a, b, stack_b);
		}
		else
			ft_rotate_stack(a, b, stack_a);
	}
	ft_sort_100_b(a, b, rank);
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
