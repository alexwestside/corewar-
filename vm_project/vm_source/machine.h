/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:46:57 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/26 16:08:45 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H
# define SIZE_BUFF 1000
# define PR_SIZE_ARENA 0x0040
# define IND_SIZE 2
# define REG_SIZE 1
# define MAX_ARGS_N MAX_ARGS_NUMBER
# define INT_MAX 2147483647
# define MSLEEP(msec) usleep(msec * 1000000.0)
# define SPACE 32
# define ESC 27
# include <fcntl.h>
# include <errno.h>
# include <ncurses.h>
# include "../../libft/libft.h"
# include "../../libft/ft_printf.h"
# include "./op.h"

enum	e_pl_color
{
	green = 1, blue, red, cyan, un_byte
};

enum	e_pl_pc_color
{
	pc_green = 10, pc_blue, pc_red, pc_cyan, pc_un_byte, w_text
};

typedef struct		s_fork
{
	int				carry;
	int				life;
	unsigned		pc;
	int				id;
	int				reg[REG_NUMBER];
	int				cmd;
	int				time_cycle;
	struct s_fork	*next;
}					t_fork;

typedef struct		s_player
{
	int				id;
	unsigned		last_live;
	unsigned		count_live;
	unsigned		magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned		prog_size;
	char			comment[COMMENT_LENGTH + 1];
	unsigned char	*code;
}					t_player;

typedef struct		s_flags
{
	char			flag;
	int				number;
}					t_flags;

typedef struct		s_machine
{
	t_fork			*head_lst;
	int				cycle;
	unsigned		count_live;
	int				iter_cycle_to_die;
	int				cycle_to_die;
	int				iter_max_checks;
	unsigned char	*arena;
	unsigned char	*color_arena;
	int				won_player;
	unsigned		count_forks;
	unsigned		count_players;
	t_player		*players;
	t_flags			flags;
}					t_machine;

typedef struct		s_m_op
{
	char			*name;
	short			params;
	short			param_types[MAX_ARGS_N];
	short			opcode;
	int				cycles;
	char			*description;
	short			carry;
	short			cod_oct;
	short			size;
}					t_m_op;

typedef struct		s_opfunc
{
	int				op;
	void			(*func)(int argvs[MAX_ARGS_N], t_fork *, t_machine *);
}					t_opfunc;

typedef struct		s_graf
{
	int				pause;
	double			speed;

}					t_graf;

static const t_m_op g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 1, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 0, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 1, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 1, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 1, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 0, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 0, 1, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 0, 1, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 0, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 1, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 0, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 0, 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

void				op_add(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_aff(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_and(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_fork(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_ld(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_ldi(int args[MAX_ARGS_N], t_fork *fork, t_machine *vm);
void				op_lfork(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_live(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_lld(int args[MAX_ARGS_N], t_fork *fork, t_machine *vm);
void				op_lldi(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_or(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_st(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_sti(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_sub(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_xor(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);
void				op_zjmp(int args[MAX_ARGS_N], t_fork *p, t_machine *vm);

/*
** func tools
*/

unsigned			move_pc(unsigned pc);
int					is_number(char *s);
int					read_vm(unsigned char *arena, int index);
void				write_vm(t_machine *vm, t_fork *forks, int index,
					int var);
int					get_arg(char bin_code, t_fork *fork, int arg,
					unsigned char *arena);
int					get_arg_ni(char bin_code, t_fork *forks, int arg,
					unsigned char *arena);
void				inheritance(t_fork *child, t_fork *father, int shift);

/*
** func validate_data
*/

int					check_argv(int num_strs, char **strs, int *i);
void				fast_check_position_argv(int num, char **strs);
int					check_read_data(t_machine *vm, int i_player, char *file);
void				check_is_champion(t_machine *vm, int fd, char *file_name);

/*
** func to working machine
*/

t_flags				get_flags(int argc, char **argv);
void				run_op_cmd(int cmd, int *args, t_fork *fork, t_machine *vm);
void				init_vm(t_machine *vm);
void				handling_args(int cmd, t_machine *vm, t_fork *iter);
void				run_vm(t_machine *vm);

/*
** func init_players
*/

t_player			*create_players(int count);
void				init_number_players(t_machine *vm, int argc, char **argv);
void				p_paths(int n, char **strs, char **paths, unsigned *count);

/*
** func func_forks
*/

t_fork				*create_fork(int id, int pc);
void				add_before(t_fork **alst, t_fork *node);
void				delete_fork(t_machine *vm, t_fork *oldfork);
void				all_delete(t_fork **alst);

/*
** func read_file
*/

char				*rev_byte(char *str, size_t size);
void				multi_parsing_files(t_machine *vm, char **strs);

/*
**  func print
*/

void				head_print(t_machine vm);
void				console_print_arena(t_machine vm);
void				is_winner(t_machine vm);
void				print_usage(void);

/*
** func delete memory
*/

void				release_memory(t_machine *vm);

/*
** func print error massages and exit
*/

void				error_exit(char *str, int code, t_machine *vm);

/*
** func graphic mode
*/

void				init_pairs(void);
void				init_window(t_machine *vm, t_graf *graf);
void				print_graph_arena(t_machine vm);
void				print_pc_arena(t_machine vm);
void				dynamic_players(t_machine vm);
void				pause_occurrent(t_machine *vm, t_graf *graf);
void				key_occurrent(t_machine *vm, t_graf *graf);
void				graph_main(t_machine vm, t_graf *grap);
void				graph_is_winner(t_machine vm);

/*
** func auxiliary func
*/

void				save_run_fork(t_fork *iter, int cmd);
void				print_dump(t_machine *vm);
void				print_flag(t_machine vm, t_player *p, int mod);

#endif