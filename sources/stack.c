/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:54:28 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 22:53:04 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*ft_new_element(long nb, size_t pos)
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

void	ft_clear_container(t_container *a, t_container *b)
{
	t_element	*temp;

	while (b->top != NULL)
	{
		temp = b->top->next;
		free(b->top);
		b->top = temp;
	}
	while (a->top != NULL)
	{
		temp = a->top->next;
		free(a->top);
		a->top = temp;
	}
}

t_container	ft_new_container(void)
{
	t_container	new_stack;

	new_stack.size = 0;
	new_stack.top = NULL;
	new_stack.bot = NULL;
	return (new_stack);
}
