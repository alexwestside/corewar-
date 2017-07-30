/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:46:57 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/12 22:47:03 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H
# define MAX_T 3						//	count byte code (T_REG, T_DIR, T_IND)
# define SIZE_BUFF 1000					// 	read data in code player (after code)
# define PR_SIZE_ARENA 0x0040			//	variable start when print with flag (d, ...)
# define GET_DIR_SIZE(cmd) g_op_tab[cmd].size ? DIR_SIZE >> 1 : DIR_SIZE
# define IS_VAL_REG(r) 0 < r && r < 17 ? 1 : 0
# include <fcntl.h>
# include <ncurses.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../op.h"

typedef struct		s_fork
{
	int				carry : 1; 			// carry flag
	int 			life : 1;			// process worker
    int 			pc;           	 	// position in char elements
	int 			id;					//	number player
	int				reg[REG_NUMBER];	// registers of the processor
}					t_fork;

typedef struct		s_forks
{
	t_fork			node;
	int 			mod;
	unsigned		time_cycle;
	t_fork			*next;
}					t_forks;

typedef	struct		s_machine
{
	t_forks			*head_lst;				// all forks
	unsigned		count_life;				// all life forks
	int				cycle_to_die_now;		// CYCLE_TO_DIE - CYCLE_DELTA each iteration
	unsigned		cycle_to_die;			// next iter to go cycle_to_die_now
	unsigned char 	*arena;					//
	t_forks			*won_player;			// last say "I am life" player
	unsigned		count_players;			// count players
	int 			*id_players;			// number players
	header_t		*players;				// vector players
	unsigned char	**code_players;			// code players
	size_t			*size_code_players;		// size code read file
}					t_machine;

typedef struct		s_flags
{
	char 			flag;
	int 			number;
}					t_flags;


typedef struct			s_m_op
{
	char				*name;
	short				params;
	short				param_types[MAX_ARGS_NUMBER];
    short				opcode;
	int					cycles;
	char				*description;
	short 				carry;
    short				cod_oct;
    short				size;
}						t_m_op;

typedef struct			s_opfunc
{
	int					op;
	void				(*func)(int argvs[MAX_ARGS_NUMBER], t_forks *,  t_machine *);
}						t_opfunc;

#endif

void					op_add(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_aff(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_and(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_fork(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_ld(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_ldi(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_lfork(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_live(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_lld(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_lldi(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_or(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_st(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_sti(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_sub(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_xor(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);
void					op_zjmp(int args[MAX_ARGS_NUMBER], t_forks *player, t_machine *vm);

/*
** func tools
*/

int     move_pc(int pc);
int		read_4_bytes(unsigned char *arena, int index);
void	write_4_bytes(t_machine *vm, t_forks *forks, int index, int var);
int		get_arg(char bin_code, t_forks *forks, int arg, unsigned char *arena);
int		get_arg_noidx(char bin_code, t_forks *forks, int arg, unsigned char *arena);




static const t_opfunc	g_opfunc[] =
		{
				{0,   &op_live},
				{1,   &op_ld},
				{2,   &op_st},
				{3,   &op_add},
				{4,   &op_sub},
				{5,   &op_and},
				{6,   &op_or},
				{7,   &op_xor},
				{8,   &op_zjmp},
				{9,   &op_ldi},
				{10,  &op_sti},
				{11,  &op_fork},
				{12,  &op_lld},
				{13,  &op_lldi},
				{14,  &op_lfork},
				{15,  &op_aff}
		};

static const t_m_op	g_op_tab[17] =
		{
				{"live",  1, {T_DIR},       								1, 10,   "alive",            0, 0, 0},
				{"ld",    2, {T_DIR | T_IND, T_REG},    					2,  5,    "load",            1, 1, 0},
				{"st",    2, {T_REG, T_IND | T_REG},    					3,  5,    "store",           0, 1, 0},
				{"add",   3, {T_REG, T_REG, T_REG},                         4,  10,   "addition",        1, 1, 0},
				{"sub",   3, {T_REG, T_REG, T_REG}, 						5,  10,   "soustraction",    1, 1, 0},
				{"and",   3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
						"et (and  r1, r2, r3   r1&r2 -> r3",    1, 1, 0},
				{"or",    3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
						"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 1, 0},
				{"xor",   3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
						"ou (xor  r1, r2, r3   r1^r2 -> r3",    1, 1, 0},
				{"zjmp",  1, {T_DIR}, 										9,  20,   "jump if zero",	 0, 0, 1},
				{"ldi",   3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,   "load index",      0, 1, 1},
				{"sti",   3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,   "store index",     0, 1, 1},
				{"fork",  1, {T_DIR},       								12, 800,  "fork",            0, 0, 1},
				{"lld",   2, {T_DIR | T_IND, T_REG},						13, 10,   "long load",       1, 1, 0},
				{"lldi",  3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,   "long load index", 1, 1, 1},
				{"lfork", 1, {T_DIR},       								15, 1000, "long fork",       0, 0, 1},
				{"aff",   1, {T_REG},										16, 2,    "aff",             0, 1, 0},
				{0,       0, {0},      										0,  0,    0,                 0, 0, 0}
		};

/*
** func validate_data
*/

int 	check_corect_data_read(t_machine vm, int index_player);
void	usage(int count, char *s);
void	work_with_flags(char **argv, int argc, t_flags *flags);
int 	is_number(char *s);
void    run_op_cmd(int cmd, int *args, t_forks *fork, t_machine *vm);

/*
** func init_players
*/

header_t		*create_players(int count);
unsigned char	**create_code_player(int count);
int 			create_point_path(int count_strs, char **strs, char **paths);


/*
** func func_forks
*/

t_fork		*create_fork(int id, int pc);

/*
** func read_file
*/

int 	multi_parsing_files(t_machine *vm, char **strs);
void	switch_data(t_machine *vm, char *data, int index_player, int i);
int 	read_data(t_machine *vm, int fd, int i);
int		read_code_player(t_machine *vm, int fd, int index);
int 	custom_read(int fd, char *buff, size_t size_buff, int ckeck);

/*
** 	func op (operation)
*/

unsigned char	*test_code_octal(t_machine *vm, unsigned char code);

/*
**  func print
*/

void	head_print(t_machine vm);
void	console_print_arena(t_machine vm);


/*
**	debug function
*/

void	test_print_code_player(t_machine vm);