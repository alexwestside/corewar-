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
	vm->count_live = 0;
	vm->iter_cycle_to_die = CYCLE_TO_DIE;
	vm->cycle_to_die = CYCLE_TO_DIE;
    vm->iter_max_checks = 0;
	vm->arena = (unsigned char *)ft_strnew(MEM_SIZE);
    vm->count_forks = 0;
	vm->won_player = 0;
	vm->players = create_players(vm->count_players);
}

int		main(int argc, char **argv)
{
	t_machine	vm;
	char		*path_files[MAX_ARGS_NUMBER];

	ft_printf("test \n\n");
	unsigned char 		s[3];

	s[0] = 0xff;
	s[1] = 0xff;
	s[2] = 0xff;
	s[3] = 0xff;

	ft_printf("%d, [%s], %d %d", *(int *)s, s, s[2], s[3]);

//	init_op();
	if (argc == 1)
		usage(1, NULL);
		// todo help use
	init_vm(&vm, create_point_path(argc - 1, argv + 1, path_files));
	if (vm.count_players == 0)
		usage(2, argv[1]);
	if (multi_parsing_files(&vm, path_files))
		usage(3, NULL);
//	work_with_flags();
	head_print(vm);
	console_print_arena(vm);
	test_print_code_player(vm);
//	test_code_octal(&vm, '\0');
	run_vm(&vm);

	int tet = -1;
	ft_printf("\n\n test %02x \n\n", (unsigned)tet);
	return (0);
}