
#include "machine.h"


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