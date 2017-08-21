

CC = gcc
#CC = clang

FLAGS = -g -Wall -Wextra -Werror

LIBFTPATH = ../libft
LIBFT = libft.a

NAME = corewar

SRCS =  main.c \
        err_exit.c \
        get_path_files.c \
        graphic_key.c \
        graphic_mode.c \
        graphic_print_tools.c \
        graphic_static.c \
        func_fork.c \
        get_args.c \
        get_flags.c \
        init.c \
        init_number_players.c \
        print.c \
        read_file.c \
        release_memory.c \
        run_op_cmd.c \
        get_flags.c \
        validate_data.c \
        work_vm.c \
        ./op_add.c \
        ./op_aff.c \
        ./op_and.c \
        ./op_fork.c \
        ./op_ld.c \
        ./op_ldi.c \
        ./op_lfork.c \
        ./op_live.c \
        ./op_lld.c \
        ./op_lldi.c \
        ./op_or.c \
        ./op_st.c \
        ./op_sti.c \
        ./op_sub.c \
        ./op_xor.c \
        ./op_zjmp.c \
        ./tools.c \
        ./tools2.c \
        ./auxiliary_func.c \

.PHONY: all clean fclean re

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	$(CC) $^ -o $(NAME) $(LIBFTPATH)/$(LIBFT) -lcurses

.c.o: $(SRCS)
	gcc $(FLAGS) -c $<

clean:
		make clean -C $(LIBFTPATH)
		rm -f $(OBJS)
		@echo OBJ_files is DEAD!!!

fclean: clean
		make fclean -C $(LIBFTPATH)
		rm -f $(NAME)
		@echo lib_files is DESTROYED!!!

re: fclean all
		@echo ALL DAMM is DESTROYED!!!
