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

void	init_vm(t_machine *vm, int argc, char **argv)
{
	vm->head_lst = NULL;
	vm->count_life = 0;
	vm->cycle_to_die_now = 0;
	vm->cycle_to_die = 0;
	vm->arena = (unsigned char *)ft_strnew(MEM_SIZE);
	vm->won_player = NULL;
	vm->count_players = (unsigned)count_players(argc, argv);
	vm->id_players = NULL;
	vm->players = create_players(vm->count_players);
	vm->code_players = NULL;
//	vm->code_players = create_code_player(vm->count_players);
	vm->size_code_players = (size_t*)malloc(vm->count_players);
}

void	test_code_octal(t_machine *vm, unsigned char code)
{
	int i;
	int mov;
	unsigned char bytecode[MAX_T];

	ft_printf("\n\nhex [%x], bin [%b]\n", vm->code_players[0][1], vm->code_players[0][1]);
	//todo in "big endian" junior byte skeep this op
	i = MAX_T; // max unsigned char it's 0xff => 0b11111111 when need to split argument xx xx xx 00
	mov = 2;
	code = vm->code_players[0][1];
	while (--i != -1)
	{
		if (i < MAX_T)
			bytecode[i] = (unsigned char)(code >> mov & 0x03);
		mov += 2;
	}
	// test
	i = -1;
	ft_printf("\n\n test code octal\n");
	while (++i < MAX_T)
		ft_printf(" %02x", bytecode[i]);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int fd;
	char name[PROG_NAME_LENGTH];

	printf("path %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("error open file \n");
	int r;
	r = (int)read(fd, name, PROG_NAME_LENGTH);
	if (r == -1)
		printf("error read data \n");
//	lseek(fd, 4, 0);
	int i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		if (name[i])
			printf("%02x ", (unsigned char)name[i]);
		i++;
	}
	lseek(fd, 4, 0);
	printf("\n");
	printf("%s\n", name);
	close(fd);


	t_machine	vm;
	int			debug;
	header_t	tes;

	ft_printf("all struct [%zu] magic [%zu] program_name [%zu], prog_size [%zu] comment [%zu]", sizeof(tes), sizeof(tes.magic), sizeof(tes.prog_name), sizeof(tes.prog_size), sizeof(tes.comment));

	if (argc == 1)
		return (1);
		// todo help use
	else if ((vm.count_players = (unsigned)count_players(argc, argv)) == 0)
		return (2);
	init_vm(&vm, argc, argv);
	debug = multi_parsing_files(&vm, argv);
	head_print(vm);
	console_print_arena(vm);
	debug == -1 ? ft_printf("Error \n") : 0;
	test_print_code_player(vm);
	test_code_octal(&vm, '\0');
	return (0);
}