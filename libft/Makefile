#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 12:25:39 by orizhiy           #+#    #+#              #
#    Updated: 2017/06/02 20:33:23 by orizhiy          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

RED = echo "\033[0;31m"
BLUE = echo "\033[0;36m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"
BYellow = echo "\033[1;33m"

NAME = libft.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC = 	ft_strstr.c \
		ft_strdel.c \
		ft_lstadd.c \
		ft_strmap.c \
		ft_strlen.c \
		ft_count_words.c \
		ft_memccpy.c \
		ft_putchar_fd.c \
		ft_strchr.c \
		ft_isspace.c \
		ft_memmove.c \
		ft_tolower.c \
		ft_strequ.c \
		ft_isalnum.c \
		ft_max_int.c \
		ft_strdup.c \
		ft_len_int.c \
		ft_strtrim.c \
		ft_isalpha.c \
		ft_memset.c \
		ft_putendl.c \
		ft_memalloc.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_striter.c \
		ft_memchr.c \
		ft_lstdelone.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_strsub.c \
		ft_memdel.c \
		ft_memcmp.c \
		ft_strjoin.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_int_min.c \
		ft_lstnew.c \
		ft_putnbr.c \
		ft_strncat.c \
		ft_isascii.c \
		ft_len_char.c \
		ft_itoa.c \
		ft_lstmap.c \
		ft_putstr.c \
		ft_strlcat.c \
		ft_putnbr_fd.c \
		ft_strsplit.c \
		ft_lstiter.c \
		ft_strcat.c \
		ft_putendl_fd.c \
		ft_memcpy_rev.c \
		ft_lstdel.c \
		ft_striteri.c \
		ft_strnew.c \
		ft_isprint.c \
		ft_strclr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strncpy.c \
		ft_putchar.c \
		ft_toupper.c \
		ft_putstr_fd.c \
		ft_strrchr.c \
		ft_strmapi.c \
		get_next_line.c \
		ft_printf.c \
		ft_printf.c \
		ft_finder.c \
		ft_parse.c \
		unsingned_size.c \
		singned_size.c \
		*ft_size_spec.c \
		*ft_flag_char.c \
		*ft_min_fild_width.c \
		*ft_precision.c \
		ft_print_format.c \
		ft_arg_void.c \
		ft_signed_int_decimal_long.c \
		ft_octal_long.c \
		ft_character.c \
		ft_octal.c \
		ft_wcharacter.c \
		ft_single_persent.c \
		ft_binary.c \
		ft_unsigned_decimal.c \
		ft_unsigned_decimal_long.c \
		ft_unsigned_hexadesimalxl.c \
		ft_unsigned_hexadesimalx.c \
		ft_signed.c \
		ft_signed_int_decimal.c \
		ft_unsigned.c \
		ft_string.c \
		ft_wstring.c \
		ft_null_format.c \
		ft_num_width.c \
		ft_put_num_base.c \
		ft_width_padd.c \
		ft_num_strlen.c \
		ft_num_len.c \
		ft_max.c \
		ft_putnstr.c \
		*ft_strndup.c \
		*ft_strnjoin.c \
		ft_strnlen.c \
		ft_check.c \
		ft_wcharlen.c

HDR = libft.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
		@echo "$$($(BYellow))LIBFT : $$($(END)) $$($(BLUE))Sources compiling...$$($(END))"
		@ar -cru $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "$$($(BYellow))LIBFT : $$($(END)) $$($(GREEN))is ALIVE!!!$$($(END))"

%.o: %.c libft.h
		@$(G) $(CFLAGS) -c -o $@ $<

clean:
		@$(DEL) $(OBJ)
		@echo "$$($(BYellow))LIBFT : $$($(END)) $$($(RED))objects is dead...$$($(RED))"

fclean: clean
		@$(DEL) $(NAME)
		@echo "$$($(BYellow))LIBFT : $$($(END))$$($(RED))DESTROYED!!!$$($(RED))"

re: all
		@echo "$$($(BYellow))LIBFT : $$($(END))$$($(RED))ALL DAMM FPS is DESTROYED!!!$$($(RED))"

norm:
		norminette $(SRC) $(HDR) | grep -B 1 "Error"


rmsh:
		rm *~
		rm \#*
		rm *.out