/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:12:45 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 23:07:45 by tshimoda         ###   ########.fr       */
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

void	ft_exit_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
