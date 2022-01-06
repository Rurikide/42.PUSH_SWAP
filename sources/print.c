/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:21:00 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 23:05:44 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_elements(t_container *a, t_container *b)
{
	t_element	*ea;
	t_element	*eb;

	ea = a->top;
	eb = b->top;
	ft_printf("AB\n");
	while (ea != NULL || eb != NULL)
	{
		if (ea == NULL)
			ft_printf(" ");
		else
		{
			ft_printf("%d", ea->nb);
			ea = ea->next;
		}
		if (eb == NULL)
			ft_printf(" ");
		else
		{
			ft_printf("%d", eb->nb);
			eb = eb->next;
		}
		ft_printf("\n");
	}
}
