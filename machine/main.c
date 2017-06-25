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
	vm = (t_machine){0, 0, 0, (unsigned char *)ft_strnew(MEM_SIZE), NULL, NULL, NULL, NULL, NULL,  vm.count_players, create_players(vm.count_players), create_code_player(vm.count_players)};
	debug = multi_parsing_files(&vm, argv);
	vm.arena = (unsigned char *)ft_strnew(MEM_SIZE);
	head_print(vm);
	console_print_arena(vm);
	debug == -1 ? ft_printf("Error \n") : 0;
	return (0);
}