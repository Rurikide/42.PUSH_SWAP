/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:18:21 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 17:45:57 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_shift_down(t_container *stack)
{
	t_element	*temp;

	if (stack->size <= 1)
		return ;
	else
	{
		temp = stack->bot;
		stack->bot->prev->next = NULL;
		stack->bot->next = stack->top;
		stack->bot = stack->bot->prev;
		stack->top->prev = temp;
		stack->top = stack->top->prev;
		stack->top->prev = NULL;
	}
}
	// OLD VERSION
	// stack->top->prev = stack->bot;
	// stack->bot->next = stack->top;
	// stack->top = stack->bot;
	// stack->bot = stack->bot->prev;
	// stack->bot->next = NULL;
	// stack->top->prev = NULL;

void	ft_reverse_stack(t_container *a, t_container *b, t_stack id)
{
	if (id == 0)
	{
		ft_shift_down(a);
		ft_printf("rra\n");
	}
	else if (id == 1)
	{
		ft_shift_down(b);
		ft_printf("rrb\n");
	}
	else if (id == 2)
	{
		ft_shift_down(a);
		ft_shift_down(b);
		ft_printf("rrr\n");
	}
}
