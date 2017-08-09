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

int		main(int argc, char **argv)
{
	t_machine	vm;
	char		*path_files[MAX_PLAYERS];

	if (argc == 1)
		usage(1, NULL, NULL);
	create_point_path(argc, argv, path_files, &vm.count_players);
	init_vm(&vm, argv);
	work_with_flags(argv, argc, &vm);
	multi_parsing_files(&vm, path_files);
	init_number_players(&vm, argc, argv);
	head_print(vm);
	//console_print_arena(vm);
	test_print_code_player(vm);
//	test_code_octal(&vm, '\0');
	run_vm(&vm);
	return (0);
}