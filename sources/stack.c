/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:54:28 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/04 23:33:10 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	ft_is_empty_stack(t_container *stack)
{
	if (stack->top == NULL && stack->bot == NULL)
		return (true);
	else
		return (false);
}

t_element	*ft_new_element(int nb, size_t pos)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	if (new == NULL)
		return (NULL);
	new->nb = nb;
	new->pos = pos;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_container	ft_new_container(void)
{
	t_container	new_stack;

	new_stack.size = 0;
	new_stack.top = NULL;
	new_stack.bot = NULL;
	return (new_stack);
}
