#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/25 21:31:22 by orizhiy           #+#    #+#              #
#    Updated: 2017/08/26 17:28:33 by orizhiy          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BLUE = echo "\033[0;36m"
RED = echo "\033[0;31m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"
BIWhite = echo "\033[1;97m"

NAME = asm
G = gcc
FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./asm_source/
SRC_NAME = 	asm_to_binary.c\
			ft_strsplit_v2.c\
			ft_command.c\
			ft_name_comment.c\
			ft_valid_command.c\
			get_sizes.c\
			hash.c\
			main.c\
			op.c\
			usage.c\
			reg_dir_ind.c\
			get_size_1.c\
			get_size_2.c\
			ft_valid_all.c\
			ft_method.c\
			ft_add_command_corewar.c\

OBJ_PATH = ./asm_source/
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

GCFLAGS = -I./asm_source -I ../libft/

LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$$($(BIWhite))ASM : $$($(END)) $$($(BLUE))Sources compiling...$$($(END))"
	@make -C ../libft/
	@$(G) $(FLAGS) $(GCFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "$$($(BIWhite))ASM : $$($(END)) $$($(GREEN))Compile with SUCCESS!$$($(END))"
	@mv asm ../

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(G) $(FLAGS) $(GCFLAGS) -o $@ -c $<

clean:
	@make -C ../libft/ clean
	@rm -f $(OBJ)
	@echo "$$($(BIWhite))ASM : $$($(END)) $$($(RED))Objects removed...$$($(END))"

fclean: clean
	@make -C ../libft/ fclean
	@rm -f $(NAME)
	@echo "$$($(BIWhite))ASM :$$($(END)) $$($(RED))Binary removed...$$($(END))"

re: fclean all
	@make -C ../libft/ re

rmsh:
		rm *~
		rm \#*
		rm *.out