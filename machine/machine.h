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
# define SIZE_BUFF 1000
# define PR_SIZE_ARENA 0x0040
# include <fcntl.h>
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
	int 			status;
	t_fork			*next;
}					t_forks;

typedef struct		s_tasks
{
	t_forks			*p_fork;
	struct s_tasks	*prev;
	struct s_tasks	*next;
	unsigned		time_cycle;
}					t_tasks;

typedef	struct		s_machine
{
	t_forks			*head_lst;				// all forks
	unsigned		count_life;				// all life forks
	unsigned		cycle_to_die_now;		// CYCLE_TO_DIE - CYCLE_DELTA each iteration
	unsigned		cycle_to_die;			// next iter to go cycle_to_die_now
	unsigned char 	*arena;					//
	t_tasks			*top;					// activity tasks (having operation comand) top
	t_tasks			*buttom;				// activity tasks (having operation comand) buttom
	t_tasks			*top_zombi;				// no activity tasks (zombi e.m. fork stay in 00 byte) top
	t_tasks			*buttom_zombi;			// no activity tasks (zombi e.m. fork stay in 00 byte) buttom
	t_forks			*won_player;			// last say "I am life" player
	unsigned		count_players;			// count players
	int 			*id_players;			// number players
	header_t		*players;				// vector players
	unsigned char	**code_players;			// code players
	size_t			*size_code_players;		// size code read file
	unsigned		*life_players_cicle;
	unsigned		*life_number_cicle;
}					t_machine;

#endif

/*
** func validate_data
*/

int		count_players(int count_strs, char **strs);


/*
** func init_players
*/

header_t		*create_players(int count);
unsigned char	**create_code_player(int count);


/*
** func func_forks
*/

t_fork		*create_fork(int id, int pc);

/*
** func func_tasks
*/

t_tasks		*create_task(t_forks *fork, int cycle_op, unsigned cycle_now);
void 		add_top(t_tasks **top, t_tasks **bottom, t_tasks *new_task);
void 		add_bottom(t_tasks **top, t_tasks **bottom, t_tasks *new_task);
int			push_before(t_tasks **iter_node, t_tasks *new_task);
void 		push(t_tasks **top, t_tasks **bottom, t_tasks *new_task);
t_tasks		*pop(t_tasks **bottom);

/*
** func read_file
*/

int 	multi_parsing_files(t_machine *vm, char **strs);
void	switch_data(t_machine *vm, char *data, int index_player, int i);
int 	read_data(t_machine *vm, int fd, int i);
int		read_code_player(t_machine *vm, int fd, int index);
int 	custom_read(int fd, char *buff, size_t size_buff, int ckeck);

/*
**  func print
*/

void	head_print(t_machine vm);
void	console_print_arena(t_machine vm);