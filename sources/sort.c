/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:22:50 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/07 20:41:47 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_2(t_container *a, t_container *b)
{
	ft_swap_elements(a, b, stack_a);
	if (ft_is_sorted(a) == true)
	{
		ft_print_elements(a, b);
		ft_printf("now sorted!\n");
	}
}

void	ft_sort_3(t_container *a, t_container *b)
{
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
	if (ft_is_sorted(a) == true)
	{
		ft_print_elements(a, b);
		ft_printf("now sorted!\n");
	}
}

void	ft_sort_4_5(t_container *a, t_container *b)
{
	(void)b;
	int nb_moves;

	nb_moves = 0;
	t_tier *rank;
	rank = (t_tier *)malloc(sizeof(t_tier));
	rank->top_tier = (size_t)1;
	rank->mid_tier = (size_t)a->size / 2;
	rank->low_tier = (size_t)a->size;
	
	while (ft_is_sorted(a) == false)
	{
		while (b->size != rank->mid_tier)
		{
			while (a->top->pos <= rank->mid_tier || a->top->next->pos <= rank->mid_tier)
			{
				if (a->top->pos <= rank->mid_tier)
				{
					ft_push_stack(a, b, stack_b);
					ft_print_elements(a, b);
					nb_moves++;
					if (a->top->pos <= rank->mid_tier)
					{
					ft_push_stack(a, b, stack_b);
					ft_print_elements(a, b);
					nb_moves++;
					}
				}
				else if (a->top->next->pos <= rank->mid_tier)
				{
					ft_rotate_stack(a, b, stack_a);
					ft_print_elements(a, b);
					nb_moves++;
					ft_push_stack(a, b, stack_b);
					ft_print_elements(a, b);
					nb_moves++;
					if (a->top->pos <= rank->mid_tier)
					{
						ft_push_stack(a, b, stack_b);
						ft_print_elements(a, b);
						nb_moves++;
					}
				}
			}
			ft_rotate_stack(a, b, stack_a);
			ft_print_elements(a, b);
			nb_moves++;
		}
		if (a->top->pos == rank->low_tier)
		{
			ft_rotate_stack(a, b, stack_a);
			ft_print_elements(a, b);
			nb_moves++;
		}
		else if (a->top->next->pos == rank->low_tier)
		{
			ft_reverse_stack(a, b, stack_a);
			ft_print_elements(a, b);
			nb_moves++;
		}
		if (a->top->pos > a->top->next->pos)
		{
			if (b->size == 2 && b->top->pos < b->bot->pos)
			{
				ft_swap_elements(a, b, both_stacks);
				ft_print_elements(a, b);
				nb_moves++;
			}
			else
			{
				ft_swap_elements(a, b, stack_a);
				ft_print_elements(a, b);
				nb_moves++;
			}
		}
	}
	if (b->top->pos < b->top->next->pos)
	{
		ft_swap_elements(a, b, stack_b);
		ft_print_elements(a, b);
		nb_moves++;
	}
	while (ft_is_empty_stack(b) == false)
	{
		ft_push_stack(b, a, stack_a);
		ft_print_elements(a, b);
		nb_moves++;
	}
	ft_printf("nb_moves = %d\n", nb_moves);
	if (ft_is_sorted(a) == true && ft_is_empty_stack(b) == true)
		ft_printf("is now sorted!\n");
}

void	ft_sort_algorithm_selection(t_container *a, t_container *b)
{
	if (ft_is_sorted(a) == true)
	{
		ft_print_elements(a, b);
		ft_printf("is already sorted!\n");
		return ;
	}
	if (a->size == 2)
		ft_sort_2(a, b);
	else if (a->size == 3)
		ft_sort_3(a, b);
	else if (a->size <= 5)
		ft_sort_4_5(a, b);
}
