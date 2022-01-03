/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:54:28 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/03 17:52:53 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool    is_empty_stack(t_container *st)
{
    if (st->top == NULL && st->bot == NULL)
        return (true);
    else
        return (false);
}

void    ft_add_front(t_container *stack, t_element *new)
{
    if (is_empty_stack(stack))
    {
        stack->top = new;
        stack->bot = new;
    }
    else
    {
        stack->top->prev = new;
        new->next = stack->top;
        stack->top = new;
    }
    stack->size++;
    return ;
}

void    ft_add_back(t_container *stack, t_element *new)
{
    if (is_empty_stack(stack))
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
    return ;
}

t_element   *ft_new_element(int nb, size_t pos)
{
    t_element *new;
    
    new = (t_element *)malloc(sizeof(t_element));
    if (new == NULL)
        return (NULL);
    new->nb = nb;
    new->pos = pos;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

t_container    new_container(void)
{
    t_container a;

    a.size = 0;
    a.top = NULL;
    a.bot = NULL;
    return(a);
}

void    ft_print_elements(t_container *a, t_container *b)
{
    t_element *ea;
    t_element *eb;

    ea = a->top;
    eb = b->top;
    
    ft_printf("[A][B]\n");
    while (ea != NULL || eb != NULL)
    {
        if (ea == NULL)
            ft_printf(" ");
        else
        {
            ft_printf("|%d|", ea->nb);
            ea = ea->next;
        }
        if (eb == NULL)
            ft_printf(" ");
        else
        {
            ft_printf("|%d|", eb->nb);
            eb = eb->next;
        }
        ft_printf("\n");
    }
    ft_printf("\n");
}