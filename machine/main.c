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

//	ft_printf("test \n\n");
//	unsigned char 		s[3];
//
//	s[0] = 0xfe;
//	s[1] = 0xff;
//	s[2] = 0xff;
//	s[3] = 0xff;
//
//	ft_printf("%d, [%s], %d %d %d %d", *(int *)s, s, s[0], s[1], s[2], s[3]);
//	return (0);

	if (argc == 1)
		print_usage();
	fast_check_position_args(argc, argv);
	create_point_path(argc, argv, path_files, &vm.count_players);
	vm.flags = work_with_flags(argc, argv);
	init_vm(&vm, argv);
	multi_parsing_files(&vm, path_files);
	init_number_players(&vm, argc, argv);
	head_print(vm);
	//console_print_arena(vm);
//	test_print_code_player(vm);
//	test_code_octal(&vm, '\0');
	run_vm(&vm);
	return (0);
}