/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:17:41 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 17:48:21 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_back(t_container *stack, t_element *new)
{
	if (ft_is_empty_stack(stack))
	{
		stack->top = new;
		stack->bot = new;
	}
	else
	{
		stack->bot->next = new;
		new->prev = stack->bot;
		stack->bot = new;
	}
	stack->size++;
}

void	ft_add_front(t_container *stack, t_element *element)
{
	if (ft_is_empty_stack(stack))
	{
		stack->top = element;
		stack->bot = element;
	}
	else
	{
		stack->top->prev = element;
		element->next = stack->top;
		stack->top = element;
	}
	stack->size++;
}

t_element	*ft_pop_top(t_container *stack)
{
	t_element	*temp;

	if (stack->top == NULL)
		return (NULL);
	if (stack->top == stack->bot)
		stack->bot = NULL;
	temp = stack->top;
	stack->top = stack->top->next;
	if (stack->top != NULL)
		stack->top->prev = NULL;
	temp->next = NULL;
	stack->size--;
	return (temp);
}

void	ft_push_stack(t_container *src, t_container *dst, t_stack id)
{
	t_element	*temp;

	temp = ft_pop_top(src);
	if (temp != NULL)
	{
		ft_add_front(dst, temp);
		if (id == 0)
			ft_printf("pa\n");
		else if (id == 1)
			ft_printf("pb\n");
	}
}
