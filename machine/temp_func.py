
#include "machine.h"

//void    check_forks(t_machine *vm, unsigned cycle)
//{
//    int     cmd;
//    t_fork *iter;
//
//    iter = vm->head_lst;
//    while (iter)
//    {
//        if (iter->mod == 1 && iter->time_cycle && cycle == iter->time_cycle)
//        {
//            handling_args(iter->cmd - 1, vm, iter);
//            iter->mod = 0;
//        }
////        iter->cmd == 15 || iter->cmd == 12 ? check_forks_before(vm, vm->cycle, iter) : 0;
//        else if (iter->mod == 0)
//        {
//            cmd = (int)vm->arena[move_pc(iter->pc)];
//            if (0 < cmd && cmd < 17)
//            {
//                iter->cmd = cmd;
//                iter->mod = 1;
//                iter->time_cycle = cycle + g_op_tab[cmd - 1].cycles;
//            }
//                iter->time_cycle =
////            else
////                iter->pc = move_pc(iter->pc + 1);
//        }
//        iter = iter->next;
//    }
//}

//void    check_forks_before(t_machine *vm, unsigned cycle, t_fork *finish)
//{
//    int     cmd;
//    t_fork *iter;
//
//    iter = vm->head_lst;
//    while (iter && iter != finish)
//    {
//        if (iter->mod == 1 && iter->time_cycle && cycle == iter->time_cycle)
//        {
//            handling_args(iter->cmd - 1, vm, iter);
//            iter->mod = 0;
//        }
//        if (iter->mod == 0)
//        {
//            cmd = (int)vm->arena[move_pc(iter->pc)];
//            if (0 < cmd && cmd < 17)
//            {
//                iter->cmd = cmd;
//                iter->mod = 1;
//                iter->time_cycle = cycle + g_op_tab[cmd - 1].cycles;
//            }
//            else
//                iter->pc = move_pc(iter->pc + 1);
//        }
//        iter = iter->next;
//    }
//}


//void	test_print_code_player(t_machine vm)
//{
//	size_t  i;
//	unsigned j;
//
//	i = -1;
//	j = -1;
//	while (++j < vm.count_players)
//	{
//		i = -1;
//		ft_printf("\n\n size code player [%u]\n", vm.players[j].prog_size);
//		ft_printf("\n\n byte code player [%d]\n", j);
//		while (++i < vm.players[j].prog_size)
//		{
//			ft_printf(" %02x", vm.players[j].code[i]);
//		}
//		ft_putchar('\n');
//	}
//}


void    debug(t_machine vm, unsigned cycle)
{

	ft_printf("\n\ndebug mode %u\n\n", cycle);
	console_print_arena(vm);

	t_fork *iter;

	iter = vm.head_lst;
	while (iter)
	{
		ft_printf("/npc: %u/n", iter->pc);
		iter = iter->next;
	}
}

//char    *get_name_player(t_machine vm, t_fork *fork)
//{
//    int i;
//
//    i = -1;
//    while (++i < vm.count_players)
//        if (vm.players[i].id == fork->id)
//            return (vm.players[i].prog_name);
//    return ("dont found name player");
//}

void    print_forks(t_fork *head)
{
	t_fork *tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("fork pc %u id %d reg[0] %d \n", tmp->pc, tmp->id, tmp->reg[0]);
		tmp = tmp->next;
	}
}

void    print_players(t_machine vm)
{
	unsigned i;

	i = -1;
	while (++i < vm.count_players)
	{
		ft_printf("players iter %d id player %d\n", i, vm.players[i].id);
	}
}