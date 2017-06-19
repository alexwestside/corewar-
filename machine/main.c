/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:35:43 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/12 23:35:46 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

// 1 help use
// 2 error print
// 0

int		main(int argc, char **argv)
{
	t_machine	vm;
	int			debug;

	if (argc == 1)
		return (1);
		// todo help use
	else if ((vm.count_players = (unsigned)count_players(argc, argv)) == 0)
		return (2);
	vm = (t_machine){0, 0, 0, ft_strnew(MEM_SIZE), NULL, NULL, NULL, NULL, NULL,  vm.count_players, create_players(vm.count_players), create_code_player(vm.count_players)};
	debug = multi_parsing_files(&vm, argv);
	debug == -1 ? ft_printf("Error \n") : 0;
	head_print(vm);
	return (0);
}