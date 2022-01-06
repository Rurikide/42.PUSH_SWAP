/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:53:55 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/05 22:51:04 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	ft_is_valid_argv(char *str)
{
	if (ft_is_valid_integer(str) == false)
		ft_exit_error();
	if (ft_is_withint_limits(str) == false)
		ft_exit_error();
	return (true);
}

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

t_bool	ft_is_withint_limits(char *str)
{
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (false);
	else
		return (true);
}

t_bool	ft_is_unique_element(t_container *a)
{
	t_element	*current_elem;
	t_element	*all_elements;
	size_t		i;
	size_t		j;

	current_elem = a->top;
	all_elements = a->top->next;
	j = 0;
	while (current_elem && current_elem->next)
	{
		i = 1;
		while (i++ + j < a->size)
		{
			if (current_elem->nb == all_elements->nb)
				ft_exit_error();
			if (all_elements->next)
				all_elements = all_elements->next;
		}
		current_elem = current_elem->next;
		if (!current_elem->next)
			return (true);
		all_elements = current_elem->next;
		j++;
	}
	return (true);
}

void	ft_parse_argv(t_container *a, char **av)
{
	char	**input;
	int		i;
	int		j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		input = ft_split(av[i], ' ');
		while (input[j])
		{
			ft_is_valid_argv(input[j]);
			ft_add_back(a, ft_new_element(ft_atoi(input[j]), 0));
			j++;
		}
		ft_free_table(input);
		i++;
	}
	if (a->top != NULL)
		ft_is_unique_element(a);
}
