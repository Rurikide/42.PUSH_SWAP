/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:53:55 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 15:14:18 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	ft_is_valid_integer(char *str)
{
	int	i;

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

void	ft_parse_argv(t_container *a, char **av)
{
	char	**input;
	int		i;
	int		j;

	i = 0;
	ft_printf("List of elements : ");
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
			ft_printf("%d ", a->bot->nb);
			j++;
		}
		i++;
	}
	ft_printf("\n\n");
}
