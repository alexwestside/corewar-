#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/26 14:42:47 by orizhiy           #+#    #+#              #
#    Updated: 2017/08/26 21:04:22 by ayatsyny         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BLUE = echo "\033[0;36m"
RED = echo "\033[0;31m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"
BIWhite = echo "\033[1;97m"

LIBFT = libft/
ASM = asm_project/
VM = vm_project/

all:
	@make -C $(LIBFT)
	@make -C $(ASM)
	@make -C $(VM)
	@echo "$$($(GREEN))__________________________________________________________$$($(END))"
	@echo "$$($(RED))COREWAR : $$($(END)) $$($(GREEN))BILD WITH SUCCESS!$$($(END))"
	@echo "$$($(RED))COREWAR : $$($(END)) $$($(GREEN))GO HARD OR GO HOME!!!$$($(END))"
	@echo "$$($(GREEN))__________________________________________________________$$($(END))"

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(ASM)
	@make clean -C $(VM)
	@echo "$$($(RED))COREWAR : $$($(END)) $$($(RED))Objects removed...$$($(END))"

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(ASM)
	@make fclean -C $(VM)
	@rm -f ./asm
	@rm -f ./corewar
	@echo "$$($(RED))COREWAR :$$($(END)) $$($(RED))Binary removed...$$($(END))"

re: fclean all

