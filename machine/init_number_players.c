

#include "machine.h"


int		check_valid_is_file(char **str, int index, int len_str, int mod)
{
    int fd;

    index += mod == 1 ? 1 : 0;
    if (index >= len_str)
        return (0);
    fd = open(str[index], O_RDONLY);
    if (fd == -1 || read(fd, 0, 0) == -1)
        return (0);
    return (1);
}

void	set_number(t_machine *vm, int index, int num)
{
    unsigned i;
    unsigned j;
    int min;
//    int tmp;

    i = -1;
    // num doesnt = 0
    while (++i < vm->count_players)
        if (vm->players[i].id == num)
        {
            j = -1;
            min = INT_MAX;
            while(++j < vm->count_players)
                if (vm->players[j].id < min)
                    min = vm->players[j].id;
            vm->players[index].id = min < 0 ? min - 1 : -1;
//            tmp = vm->players[index].id;
            break ;
        }
    if (num && vm->players[index].id == 0)
        vm->players[index].id = num;
}

// виключити флагі які потрібні для бонусного режиму в argc і argv і передати
// у функцію
void	init_number_players(t_machine *vm, int argc, char **argv)
{
    int i;	// iter to arg
    unsigned j;	// iter to players
    int num;

    i = 0;
    j = -1;
    num = 0;
    while (++i < argc)
        if (!ft_strcmp(argv[i], "-n"))
        {
            if (i + 1 < argc && is_number(argv[++i]) &&
                check_valid_is_file(argv, i, argc, 1))
            {
                num = ft_atoi(argv[i]);
                if (j + 1 < vm->count_players)
                    set_number(vm, ++j, num);
            }
        }
        else if (check_valid_is_file(argv, i, argc, 0))
            if (j + 1 < vm->count_players)
                set_number(vm, ++j, num);
}
