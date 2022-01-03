/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:12:45 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/03 15:43:51 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool ft_is_valid_integer(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (false);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (false);
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }    
    return (true);
}