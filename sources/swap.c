/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:17:49 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 17:48:00 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_second_is_first(t_container *stack)
{
	if (stack->size <= 1)
		return ;
	stack->top = stack->top->next;
	stack->top->prev->next = stack->top->next;
	stack->top->prev->prev = stack->top;
	if (stack->top->next != NULL)
		stack->top->next->prev = stack->top->prev;
	stack->top->next = stack->top->prev;
	stack->top->prev = NULL;
}

void	ft_swap_elements(t_container *a, t_container *b, t_stack id)
{
	if (id == 0)
	{
		ft_second_is_first(a);
		ft_printf("sa\n");
	}
	else if (id == 1)
	{
		ft_second_is_first(b);
		ft_printf("sb\n");
	}
	else if (id == 2)
	{
		ft_second_is_first(a);
		ft_second_is_first(b);
		ft_printf("ss\n");
	}
	return ;
}
