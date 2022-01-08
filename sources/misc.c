/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:13:46 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/08 15:41:59 by tshimoda         ###   ########.fr       */
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

void	ft_index_elements_core(t_container *a, int i, size_t count)
{
	(void)i;
	a->top->pos = (size_t)a->size - count;
	if (a->top->next)
		a->top = a->top->next;
}

//	ft_printf("ELEMENT #%d index position = %d\n", i, a->top->pos);
//	ft_printf("ELEMENT #%d value = %d\n", i, elem_nb[i]);

void	ft_index_elements(t_container *a, int i, int j, size_t count)
{
	t_element	*temp;
	int			*elem_nb;

	elem_nb = (int [1000]){0};
	temp = a->top;
	while (i++ < (int)a->size)
	{
		elem_nb[i] = temp->nb;
		temp = temp->next;
	}
	temp = a->top;
	i = 1;
	while (a->top->pos == 0)
	{
		count = 0;
		j = 0;
		while (j++ < (int)a->size)
		{
			if (elem_nb[i] < elem_nb[j])
				count++;
		}
		ft_index_elements_core(a, i, count);
		i++;
	}
	a->top = temp;
}
