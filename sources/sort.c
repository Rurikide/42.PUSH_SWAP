/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:22:50 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/06 21:50:22 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_sort_algo(t_container *a, t_container *b)
{
    if (a->size == 3)
    {
        if (ft_is_sorted(a) == true)
		{
            ft_clear_container(a, b);
		    ft_printf("already sorted!\n");
		}
        else if (a->top->pos == 3)
        {
            ft_rotate_stack(a, b, stack_a);
            ft_print_elements(a, b);
            if (a->top->pos == 2)
            {
                ft_swap_elements(a, b, stack_a);
                ft_print_elements(a, b);
            }
        }
        else if (a->top->pos == 2)
        {
            if (a->bot->pos == 1)
            {
                ft_reverse_stack(a, b, stack_a);
                ft_print_elements(a, b);
            }
            else
            {
                ft_swap_elements(a, b, stack_a);
                ft_print_elements(a, b);
            }
        }
        else if (a->top->pos == 1 && a->bot->pos == 2)
        {
            ft_reverse_stack(a, b, stack_a);
            ft_swap_elements(a, b, stack_a);
            ft_print_elements(a, b);
        }
        
    }
}