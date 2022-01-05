/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:18:12 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 17:46:27 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_shift_up(t_container *stack)
{
	t_element	*temp;

	if (stack->size <= 1)
		return ;
	else
	{
		temp = stack->top;
		stack->top->next->prev = NULL;
		stack->top->prev = stack->bot;
		stack->top = stack->top->next;
		stack->bot->next = temp;
		stack->bot = stack->bot->next;
		stack->bot->next = NULL;
	}
}
	// OLD VERSION
	// 	stack->top->prev = stack->bot;
	// 	stack->bot->next = stack->top;
	// 	stack->bot = stack->top;
	// 	stack->top = stack->top->next;
	// 	stack->bot->next = NULL;
	// 	stack->top->prev = NULL;

void	ft_rotate_stack(t_container *a, t_container *b, t_stack id)
{
	if (id == 0)
	{
		ft_shift_up(a);
		ft_printf("ra\n");
	}
	else if (id == 1)
	{
		ft_shift_up(b);
		ft_printf("rb\n");
	}
	else if (id == 2)
	{
		ft_shift_up(a);
		ft_shift_up(b);
		ft_printf("rr\n");
	}
}
