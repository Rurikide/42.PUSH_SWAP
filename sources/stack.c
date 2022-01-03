/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:54:28 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/02 21:24:45 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool    is_empty_stack(t_stack *st)
{
    if (st == NULL)
        return (true);
    else
        return (false);
}

t_stack *add_stack_element(t_stack *st, int x)
{
    t_element   *element;

    element = malloc(sizeof(*element));
    if (element == NULL)
    {
        write (1, "Error", 5);
        write (1, "\n", 1);
        exit(0);
    }
    element->nb = x;
    element->prev = NULL;
    element->next = NULL;
    if (is_empty_stack(st))
    {
        st = malloc (sizeof(st));
        if (st == NULL)
        {
            write (1, "Error", 5);
            write (1, "\n", 1);
            exit(0);
            st->len = 0;
            st->top = element;
            st->end = element;
        }
    }
    else
    {
        st->end->next = element;
        element->prev = st->end;
        st->end = element;
    }
    st->len++;
    return (st);
}
// FONCTION INTERDITE A ENLEVER : PRINTF
#include <stdio.h>

void    print_stack_element(t_stack *st)
{
    t_element *temp;

    if (is_empty_stack(st))
    {
        write (1, "Vide", 4);
        write (1, "\n", 1);
        return ;
    }
    temp = st->top;
    while(temp->next != NULL)
    {
        printf("[%d] ", temp->nb);
        temp = temp->next;
    }
    free(temp);
    printf("\n");
}