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

int	main(int argc, char **argv)
{
	t_machine	vm;
	char		*path_files[MAX_PLAYERS];

	if (argc == 1)
		print_usage();
	fast_check_position_args(argc, argv);
	ft_bzero(path_files, ((MAX_PLAYERS + 1) * sizeof(char *)));
	p_paths(argc, argv, path_files, &vm.count_players);
	vm.flags = work_with_flags(argc, argv);
	init_vm(&vm, argv);
	multi_parsing_files(&vm, path_files);
	init_number_players(&vm, argc, argv);
	run_vm(&vm);
	return (0);
}
