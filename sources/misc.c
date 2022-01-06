/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:13:46 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 22:52:49 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol_core(char *str)
{
	int		i;
	long	nombre;

	i = 0;
	nombre = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nombre = (nombre * 10) + (str[i] - 48);
		i++;
	}
	return (nombre);
}

long	ft_atol(char *str)
{
	int		i;
	int		minus;
	long	nombre;

	i = 0;
	minus = 1;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	nombre = ft_atol_core(&str[i]);
	nombre = nombre * minus;
	return (nombre);
}
