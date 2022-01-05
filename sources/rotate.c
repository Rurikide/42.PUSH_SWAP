/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:18:12 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 13:04:15 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_shift_up(t_container *stack)
{
	// TEMPORAIRE, plutôt vérifier si la stack est vide dans la partie algorithme et non dans les actions
	if (ft_is_empty_stack(stack))
	{
		return ;
	}
	else
	{
		stack->top->prev = stack->bot;
		stack->bot->next = stack->top;
		stack->bot = stack->top;
		stack->top = stack->top->next;
		stack->bot->next = NULL;
		stack->top->prev = NULL;
	}
	return ;
}

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
	return ;
}

