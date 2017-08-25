#ifndef ASM_H_H
#define ASM_H_H

#include "corewar.h"
#include "corewar_valid.h"

#define HEX_BASE "0123456789abcdef"

void			ft_asm(t_corewar *corewar);
void			get_prog_size(header_t *header, t_corewar *corewar, int fd);
void			bot_code_to_binary(t_corewar *corewar, int fd, int current_line);
void			args_to_bytes(t_command *command, int fd, t_corewar *corewar, int current_line);
void			t_reg_to_byte(char *command_data, int fd);
//void			t_dir_to_byte(char *command_name, char *command_data, int fd, t_corewar *corewar, int current_line);
void	t_dir_to_byte(char **data, int fd, t_corewar *corewar, int current_line);
//void	t_dir_to_byte(char **data, int fd, t_corewar *corewar, int current_line, int dir_num);
//void			t_dir_to_byte(char **data, int fd, t_corewar *corewar, int current_line);
void			t_ind_to_byte(char *command_data, int fd);
//size_t			get_distance_to_method(char *command_name, t_corewar * corewar);
size_t	get_distance_to_method(char *command_name, t_corewar *corewar, size_t distance, t_command *hash_command);
void get_distance_to_method_1(size_t *distance, t_command *command);
void get_distance_to_method_2(size_t *distance, t_command **hash_command);
size_t			get_distance_to_command(t_corewar *corewar, int current_line);
int				get_size_args(t_command *command);
size_t			get_t_dir_size(char *command_name);
void			get_code_byte(t_command *_command, int fd);
void			type_command(t_bot bot, t_command *command, int fd);
void			hex(int n, int fd);
void			hex_magic(int n, int fd, char *str, size_t *i);
unsigned int	reverse_magic(unsigned int magic);
unsigned int	swap_bytes(char *s, size_t size);
void			t_reg_to_byte(char *command_data, int fd);
void			run_throw_command(int fd, t_command *h_command, t_corewar *corewar, int *current_line);
#endif