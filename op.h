/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2017/06/05 19:14:08 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/
#define IND_SIZE 2
#define REG_SIZE 4
#define DIR_SIZE REG_SIZE


# define REG_CODE 1
# define DIR_CODE 2
# define IND_CODE 3


#define MAX_ARGS_NUMBER 4
#define MAX_PLAYERS 4
#define MEM_SIZE 4096 /*(4*1024)*/
#define IDX_MOD 512 /*(MEM_SIZE / 8)*/
#define CHAMP_MAX_SIZE 682 /*(MEM_SIZE / 6)*/

#define COMMENT_CHAR '#'
#define COMMENT_CHAR2 ';'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

#define REG_NUMBER 16

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 50
#define NBR_LIVE 21
#define MAX_CHECKS 10

/*
**
*/

typedef char t_arg_type;

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

/*
**
*/

# define PROG_NAME_LENGTH 128 /*(128)*/
# define COMMENT_LENGTH 2048 /*(2048)*/
# define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct 		header_s
{
    unsigned int	magic;
    char 			prog_name[PROG_NAME_LENGTH + 1];
    unsigned int 	prog_size;
    char 			comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct s_op
{
    char	*command_name;
    int		count_args;
    int		args[3][3];
    int		opcode;
    int		cycles;
    char	*description;
    int		carry;
    int		cod_octal;
}				t_op;

extern t_op op_tab[17];

t_op *init_op();


//t_op init_op(t_op *op);
