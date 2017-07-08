
#include "machine.h"

unsigned char	*test_code_octal(t_machine *vm, unsigned char code)
{
	int i;
	int mov;
	unsigned char *bytecode;

	bytecode = (unsigned char *)ft_strnew(MAX_T - 1);
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
	return (bytecode);

}

//int 	*code_octal(int code)
//{
//	int bytecode[3];
//
//
//}

/*
 *  !!!!! don't delete some func it is important !!!!!!
 */


//void	select_op(t_machine vm, t_forks *task)
//{
//	static void	(*func_select[17])(t_machine *, t_forks *);
//
//	func_select[0] = live;
//	func_select[1] = ld;
//	func_select[2] = st;
//	func_select[3] = add;
//	func_select[4] = sub;
//	func_select[5] = and;
//	func_select[6] = or;
//	func_select[7] = xor;
//	func_select[8] = zjmp;
//	func_select[9] = ldi;
//	func_select[10] = sti;
//	func_select[11] = fork;
//	func_select[12] = lld;
//	func_select[13] = lldi;
//	func_select[14] = lfork;
//	func_select[15] = aff;
//

	// todo change carry
//	func_select[task->node.pc](vm, task);
//}


void	sti(t_machine *vm, t_forks *fork)
{
	size_t p_pc;
	int sum;
	unsigned char *bytecode;
	int i;

	i = 0;
	p_pc = fork->node.pc;
	if (op_tab[p_pc].carry)
		bytecode = test_code_octal(vm, vm->arena[(p_pc + 1) % MEM_SIZE]);
	// todo create func to check correctly bytecode and run func when have bytecode
	sum = 0;
	while (++i < op_tab[p_pc].count_args)
	{
		sum += bytecode[i] == REG_CODE ? (int)vm->arena[(p_pc + 2) % MEM_SIZE] : 0;
		sum += bytecode[i] == DIR_CODE ? (int)vm->arena[(p_pc + 4) % MEM_SIZE]: 0; // {"sti", 3, {0, 0, 0}, 11, 25, "store index", 1, 1},
																					// last element 1 == 2b in DIR_CODE
		sum += bytecode[i] == IND_CODE ? (int)vm->arena[(p_pc + 6) % MEM_SIZE]: 0;
	}

	free(bytecode);
}