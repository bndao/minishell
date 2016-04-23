/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:46:54 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 18:59:38 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					main(int ac, char **av, char **env)
{
	t_env	*e;

	ft_putstr(CLEAR);
	if (ac == 1)
		ft_putstr(av[0]);
	ft_putchar('\n');
	// ft_putendl(ft_strcut(env[0], '='));
	// print_that_tab(env);
	e = env_to_list(env);
	print_that_list(e);
	// while (get_next_line(0, &line))
	// ft_putnbr(fields(env));
	return (0);
}
