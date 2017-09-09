#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/26 17:32:15 by orizhiy           #+#    #+#              #
#    Updated: 2017/08/27 10:59:38 by ayatsyny         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BLUE = echo "\033[0;36m"
RED = echo "\033[0;31m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"
BIWhite = echo "\033[1;97m"

NAME = corewar
G = gcc
FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./vm_source/
SRC_NAME =  main.c \
        err_exit.c \
        get_path_files.c \
        graphic_key.c \
        graphic_mode.c \
        graphic_print_tools.c \
        graphic_static.c \
        func_fork.c \
        get_args.c \
        init.c \
        init_number_players.c \
        print.c \
        read_file.c \
        release_memory.c \
        run_op_cmd.c \
        get_flags.c \
        validate_data.c \
        work_vm.c \
        op_add.c \
        op_aff.c \
        op_and.c \
        op_fork.c \
        op_ld.c \
        op_ldi.c \
        op_lfork.c \
        op_live.c \
        op_lld.c \
        op_lldi.c \
        op_or.c \
        op_st.c \
        op_sti.c \
        op_sub.c \
        op_xor.c \
        op_zjmp.c \
        tools.c \
        tools2.c \
        auxiliary_func.c \

OBJ_PATH = ./vm_source/
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

GCFLAGS = -I./vm_source -I ../libft/

LIBFT = ../libft/libft.a

.PHONY: all clean fclean re rmsh

$(NAME): $(OBJ)
	@echo "$$($(BIWhite))VM -> $$($(END))$$($(BLUE))Sources compiling...$$($(END))"
	@$(G) $(FLAGS) $(GCFLAGS) -o $@ $(OBJ) $(LIBFT) -lcurses
	@echo "$$($(BIWhite))VM -> $$($(END))$$($(GREEN))Compile with SUCCESS!$$($(END))"
	@mv corewar ../

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(G) $(FLAGS) $(GCFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "$$($(BIWhite))VM -> $$($(END))$$($(RED))Objects removed...$$($(END))"

fclean: clean
	@rm -f $(NAME)
	@echo "$$($(BIWhite))VM -> $$($(END))$$($(RED))Binary removed...$$($(END))"

re: fclean all

rmsh:
	rm *~
	rm \#*
	rm *.out
