/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:34:58 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/13 13:35:42 by tshimoda         ###   ########.fr       */
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

size_t	ft_find_element(t_container *stack, size_t x)
{
	size_t		index;
	t_element	*scan;

	scan = stack->top;
	index = 0;
	while (scan->pos != x)
	{
		scan = scan->next;
		index++;
	}
	return (index);
}
