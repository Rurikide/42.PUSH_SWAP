/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 22:24:19 by tshimoda          #+#    #+#             */
/*   Updated: 2022/01/02 21:06:25 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_container	a;
	t_container	b;

	a = ft_new_container();
	b = ft_new_container();
	if (ac > 1)
	{
		ft_parse_argv(&a, &av[1], 0, 0);
		ft_sort_algorithm_selection(&a, &b);
		ft_clear_container(&a, &b);
	}
	return (0);
}
