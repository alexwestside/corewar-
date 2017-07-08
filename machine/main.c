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


void	init_vm(t_machine *vm, int count_player)
{
	vm->count_players = (unsigned)count_player;
	if (vm->count_players == 0)
		return ;
	vm->head_lst = NULL;
	vm->count_life = 0;
	vm->cycle_to_die_now = 0;
	vm->cycle_to_die = 0;
	vm->arena = (unsigned char *)ft_strnew(MEM_SIZE);
	vm->won_player = NULL;
	vm->id_players = NULL;
	vm->players = create_players(vm->count_players);
	vm->code_players = NULL;
//	vm->code_players = create_code_player(vm->count_players);
	vm->size_code_players = (size_t*)malloc(vm->count_players);
}

int		main(int argc, char **argv)
{
	t_machine	vm;
	char		*path_files[MAX_ARGS_NUMBER];

	init_op();
	if (argc == 1)
		usage(1, NULL);
		// todo help use
	init_vm(&vm, create_point_path(argc - 1, argv + 1, path_files));
	if (vm.count_players == 0)
		usage(2, argv[1]);
	if (multi_parsing_files(&vm, path_files))
		usage(3, NULL);
	head_print(vm);
	console_print_arena(vm);
	test_print_code_player(vm);
	test_code_octal(&vm, '\0');

	int tet = -1;
	ft_printf("\n\n test %02x \n\n", (unsigned)tet);
	return (0);
}