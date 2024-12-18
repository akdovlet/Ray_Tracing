# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 10:04:18 by akdovlet          #+#    #+#              #
#    Updated: 2024/12/18 18:44:03 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# get all files with ls -d */*/* | sort

NAME	:=	minirt

SRC		:=	main.c						\
			matrix/matrix.c				\
			mlx/init_mlx.c				\
			mlx/key_manager.c			\
			mlx/mlx_clear.c				\
			mlx/mlx_pixel_put.c			\
			tuple/color_new.c			\
			tuple/hadamard_product.c	\
			tuple/simulation.c			\
			tuple/tuple_add.c			\
			tuple/tuple_cmp.c			\
			tuple/tuple_cross.c			\
			tuple/tuple_dot.c			\
			tuple/tuple_magnitude.c		\
			tuple/tuple_negate.c		\
			tuple/tuple_new.c			\
			tuple/tuple_normalize.c		\
			tuple/tuple_scalar.c		\
			tuple/tuple_substract.c

SRC_DIR	:=	src
BUILD	:=	.build

SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ 	:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))
DEP		:=	$(OBJ:.o=.d)

CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -MMD -MP -Iinclude -g -Imlx_linux
MATH	:=	-lm

all: create_dir $(NAME)

create_dir: | $(BUILD)

print:
	@echo $(OBJ)

$(BUILD):
	@mkdir -p $(BUILD)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(MATH)
	@printf "\033[1;32%sm\t$(NAME) ready\033[0m\n";

$(BUILD)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1;32%sm\tCompiled: $(<F)\033[0m\n";

clean:
	@if [ -d $(BUILD) ]; then $(RM) -rf $(BUILD) && printf "\033[1;31m\tDeleted: $(NAME) $(BUILD)\033[0m\n"; fi

fclean:
	@make --no-print-directory clean
	@if [ -f $(NAME) ]; then $(RM) -rf $(NAME) && printf "\033[1;31m\tDeleted: $(NAME)\033[0m\n"; fi

full: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes ./${NAME}

re:
	@make --no-print-directory fclean
	@make --no-print-directory all

-include $(DEP)

.PHONY: all clean fclean re create_dir

