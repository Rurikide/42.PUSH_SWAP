/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 22:37:03 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/02 21:29:56 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef enum bool
{
    false,
    true
} bool;

typedef struct s_element
{
    int     nb;
    int     pos;
    struct  s_element *prev;
    struct  s_element *next;
    
}t_element;

typedef struct s_stack
{
    int     len;
    struct  s_element *top;
    struct  s_element *end;
}t_stack;


bool    is_empty_stack(t_stack *st);
t_stack *add_stack_element(t_stack *st, int x);
void    print_stack_element(t_stack *st);

#endif