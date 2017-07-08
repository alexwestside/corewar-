
#include "machine.h"

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

int 	*code_octal(int code)
{
	int bytecode[3];


}


void	select_op(t_machine vm, t_forks *task)
{
	static void	(*func_select[17])(t_machine *, t_forks *);

	func_select[0] = live;
	func_select[1] = ld;
	func_select[2] = st;
	func_select[3] = add;
	func_select[4] = sub;
	func_select[5] = and;
	func_select[6] = or;
	func_select[7] = xor;
	func_select[8] = zjmp;
	func_select[9] = ldi;
	func_select[10] = sti;
	func_select[11] = fork;
	func_select[12] = lld;
	func_select[13] = lldi;
	func_select[14] = lfork;
	func_select[15] = aff;

	func_select[task->node.pc](vm, task);
}