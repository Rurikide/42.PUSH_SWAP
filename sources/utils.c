/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:12:45 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/08 15:43:19 by tshimoda         ###   ########.fr       */
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

t_bool	ft_is_sorted(t_container *stack)
{
	t_element	*temp;

	temp = stack->top;
	while (temp && temp->next)
	{
		if (temp->nb < temp->next->nb)
		{
			temp = temp->next;
		}
		else
			return (false);
	}
	return (true);
}

t_tier	*ft_set_tier_info(t_container *a)
{
	t_tier	*rank;

	rank = (t_tier *)malloc(sizeof(t_tier));
	if (!rank)
		return (NULL);
	rank->top_tier = (size_t)1;
	rank->mid_tier = (size_t)a->size / 2;
	rank->low_tier = (size_t)a->size;
	return (rank);
}

size_t	ft_scan_top_tier_elements(t_container *a, t_tier *rank)
{
	t_element	*temp;
	size_t		top_index;

	top_index = 0;
	temp = a->top;
	while (temp->next != NULL)
	{
		if (temp->pos <= rank->mid_tier)
			break ;
		temp = temp->next;
		top_index++;
	}
	return (top_index);
}

void	ft_exit_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
