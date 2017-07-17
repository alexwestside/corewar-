#ifndef ASM_H_H
#define ASM_H_H

#include "corewar.h"
#include "corewar_valid.h"

#define HEX_BASE "0123456789abcdef"

void _asm(t_corewar corewar);
void asm_to_binary(t_corewar *corewar);
void get_prog_size(header_t *header, t_corewar *corewar, int fd);
void bot_code_to_binary(t_corewar *corewar, int fd);
void args_to_bytes(t_command *command, int fd, t_hash_table *hash, t_corewar *corewar);
void t_REG_to_byte(char *command_name, char *command_data, int fd);
void t_DIR_to_byte(char *command_name, char *command_data, int fd, t_hash_table *hash, t_corewar *corewar);
void t_IND_to_byte(char *command_name, char *command_data, int fd);
size_t get_distance_to_method(char *command_name, /*t_hash_table *hash, */t_corewar * corewar);
int get_size_args(t_command *command);
size_t get_t_dir_size(char *command_name);
void get_code_byte(t_command *_command, int fd);
void type_command(t_bot bot, t_command *command, int fd);
int count_arg(t_command *_command);
void get_zjmp_distance(char *command_name, char *command_data, int fd, t_corewar *corwar);

void hex(int n, int fd);
void hex_magic(int n, int fd, char *str, size_t *i);
unsigned int reverse_magic(unsigned int magic);
int swap_bytes(char *s, size_t size);



int binary_type_args(int i, int arg);
int ft_isdigit_str(char *s);
void print_hex_magic(char *str, int fd);
void str_to_hex(char *str, int fd, int len);


#endif