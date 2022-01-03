/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:53:55 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/03 16:18:14 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_parse_argv(t_container *a, char **av)
{
    char **input;
    int i;
    int j;

    i = 0;
    while (av[i] != NULL)
    {
        j = 0;
        input = ft_split(av[i], ' ');
        while (input[j])
        {
            if (!ft_is_valid_integer(input[j]))
            {
                ft_printf("%s Error\n", input[j]);
                exit (0);
            }
            ft_add_back(a, ft_new_element(ft_atoi(input[j]), 0));
            ft_printf("%d\n", a->bot->nb);
            j++;
        }
        i++;
    }
}