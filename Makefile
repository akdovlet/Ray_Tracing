# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 10:04:18 by akdovlet          #+#    #+#              #
#    Updated: 2025/01/10 20:30:49 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# get all files with ls -d */*/* | sort

NAME	:=	minirt

SRC		:=	main.c							\
			scene.c							\
			camera/camera.c					\
			graphics/graphics.c				\
			light/light.c					\
			light/shading.c					\
			matrix/rotate.c					\
			matrix/transform.c				\
			matrix/degrees_to_radians.c		\
			matrix/matrix_cmp.c				\
			matrix/matrix_determinant.c		\
			matrix/matrix_inverse.c			\
			matrix/matrix_multiply.c		\
			matrix/matrix_print.c			\
			matrix/matrix_transpose.c		\
			matrix/matrix.c					\
			objects/material.c				\
			objects/normal.c				\
			objects/plane.c					\
			objects/ray_transform.c			\
			objects/ray.c					\
			objects/reflect.c				\
			objects/sphere.c				\
			optimizations/quadtree/configuration/set_quadtree.c			\
			optimizations/quadtree/quadtree.c							\
			optimizations/quadtree/traverse.c							\
			optimizations/optimizations.c								\
			optimizations/find_ambiguity.c								\
			optimizations/find_shape.c									\
			pattern/gradient.c				\
			pattern/pattern.c				\
			pattern/stripe.c				\
			render/render.c					\
			render/ray_for_pixel.c			\
			tuple/hadamard_product.c		\
			tuple/tuple_add.c				\
			tuple/tuple_cmp.c				\
			tuple/tuple_cross.c				\
			tuple/tuple_dot.c				\
			tuple/tuple_magnitude.c			\
			tuple/tuple_negate.c			\
			tuple/tuple_new.c				\
			tuple/tuple_normalize.c			\
			tuple/tuple_print.c				\
			tuple/tuple_scalar.c			\
			tuple/tuple_substract.c			\
			vector/vector.c					\
			world/pre_compute.c				\
			world/view_transform.c			\
			world/world.c

SRC_DIR	:=	src
BUILD	:=	.build

SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ 	:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))
DEP		:=	$(OBJ:.o=.d)

LIBFT	:=	libs/libft/libft.a
RAYLIB	?=	libs/raylib/src/

CC		:=	cc

CFLAGS				:= -Wall  -Wextra -Werror
DEBUG_FLAGS			:= -MMD -MP -g 
OPTI_FLAGS			:= -O3
FLAGS				:= $(CFLAGS) $(DEBUG_FLAGS) #$(OPTI_FLAGS)

INCLUDES_BASIC		:= -I include -I libs/libft/include
INCLUDES_MANDATORY	:= -Imlx_linux
INCLUDES_BONUS		:= -I $(RAYLIB)
INCLUDES			:= $(INCLUDES_BASIC) $(INCLUDES_BONUS)

LINK_BASIC			:= -lm
LINK_MANDATORY		:= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz
LINKK_BONUS			:= -L $(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
LINK				:= $(LINK_BASIC) $(LINKK_BONUS)

all: create_dir $(NAME)

create_dir: | $(BUILD)

print:
	@echo $(OBJ)

$(BUILD):
	@mkdir -p $(BUILD)

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(LINK) -o $(NAME) $(LIBFT) $(MATH)

$(BUILD)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "\033[1;32%sm\tCompiled: $(<F)\033[0m\n";

$(LIBFT):
	@$(MAKE) --no-print-directory -C libs/libft

clean:
	@if [ -d $(BUILD) ]; then $(RM) -rf $(BUILD) && printf "\033[1;31m\tDeleted: $(NAME) $(BUILD)\033[0m\n"; fi
	@$(MAKE) --no-print-directory clean -C libft

fclean:
	@make --no-print-directory clean
	@if [ -f $(NAME) ]; then $(RM) -rf $(NAME) && printf "\033[1;31m\tDeleted: $(NAME)\033[0m\n"; fi
	@$(MAKE) --no-print-directory fclean -C libft

full: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes ./${NAME}

run:
	@make --no-print-directory all && ./minirt

re:
	@make --no-print-directory fclean
	@make --no-print-directory all

build_raylib:
	cd libs/raylib/src
	make PLATFORM=PLATFORM_DESKTOP
-include $(DEP)

.PHONY: all clean fclean re create_dir

