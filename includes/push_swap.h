/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 22:37:03 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 14:10:52 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libsources/libft.h"
# include "../libft/libsources/ft_printf.h"

typedef enum bool
{
	false,
	true
}	t_bool;

typedef enum stack
{
	stack_a,
	stack_b,
	both_stacks
}	t_stack;

typedef struct s_element
{
	int					nb;
	size_t				pos;
	struct s_element	*prev;
	struct s_element	*next;
}t_element;

typedef struct s_container
{
	size_t				size;
	struct s_element	*top;
	struct s_element	*bot;
}t_container;

t_container	ft_new_container(void);
t_element	*ft_new_element(int nb, size_t pos);
t_element	*ft_pop_top(t_container *stack);
t_bool		ft_is_empty_stack(t_container *stack);
t_bool		ft_is_valid_integer(char *str);
void		ft_parse_argv(t_container *a, char **av);
void		ft_print_elements(t_container *a, t_container *b);
void		ft_add_front(t_container *stack, t_element *element);
void		ft_add_back(t_container *stack, t_element *new);
void		ft_push_stack(t_container *src, t_container *dst, t_stack id);
void		ft_second_is_first(t_container *stack);
void		ft_swap_elements(t_container *a, t_container *b, t_stack id);
void		ft_shift_up(t_container *stack);
void		ft_shift_down(t_container *stack);
void		ft_rotate_stack(t_container *a, t_container *b, t_stack id);
void		ft_reverse_stack(t_container *a, t_container *b, t_stack id);
#endif