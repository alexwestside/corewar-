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
# include <fcntl.h>
# include <ncurses.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../op.h"

typedef struct		s_fork
{
	int				carry : 1; 			// carry flag
	int 			life : 1;			// process worker
	size_t			pc;           	 	// position in char elements
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
	unsigned		cycle_to_die_now;		// CYCLE_TO_DIE - CYCLE_DELTA each iteration
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

#endif

/*
** func validate_data
*/

int 	check_corect_data_read(t_machine vm, int index_player);
void	usage(int count, char *s);


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