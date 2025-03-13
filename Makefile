# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 10:04:18 by akdovlet          #+#    #+#              #
#    Updated: 2025/03/13 17:11:49 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# get all files with ls -d */*/* | sort

NAME	:=	minirt

SRC		:=	main.c							\
			test.c							\
			scenes.c						\
			camera/camera.c					\
			camera/view_transform.c			\
			colors/colors.c					\
			colors/get_emission.c			\
			colors/more_colors.c			\
			light/light.c					\
			light/shading.c					\
			mlx/init_mlx.c					\
			mlx/key_manager.c				\
			mlx/mlx_clear.c					\
			mlx/mlx_pixel_put.c				\
			mlx/pixel_at.c					\
			shapes/cube.c					\
			pattern/checker.c				\
			pattern/cubical_map.c			\
			pattern/cylindrical_map.c		\
			pattern/gradient.c				\
			pattern/planar_map.c			\
			pattern/pattern.c				\
			pattern/radial.c				\
			pattern/ring.c					\
			pattern/stripe.c				\
			pattern/uv_mapping.c			\
			pattern/texture_map.c			\
			ray/ray_transform.c				\
			ray/cache_ray.c					\
			ray/ray.c						\
			ray/reflect.c					\
			ray/refract.c					\
			ray/schlick.c					\
			render/path_tracing.c			\
			render/per_pixel.c				\
			render/render.c					\
			shapes/cone.c					\
			shapes/cylinder_intersect.c		\
			shapes/cylinder.c				\
			shapes/glass_sphere.c			\
			shapes/material.c				\
			shapes/normal.c					\
			shapes/plane.c					\
			shapes/sphere.c					\
			shapes/triangle.c				\
			math/matrix/rotate.c			\
			math/matrix/transform.c			\
			math/matrix/degrees_to_radians.c\
			math/matrix/matrix_cmp.c		\
			math/matrix/matrix_determinant.c\
			math/matrix/matrix_inverse.c	\
			math/matrix/matrix_multiply.c	\
			math/matrix/matrix_print.c		\
			math/matrix/matrix_transpose.c	\
			math/matrix/matrix.c			\
			math/color_new.c				\
			math/float_swap.c				\
			math/hadamard_product.c			\
			math/interpolation.c			\
			math/random.c					\
			math/time.c						\
			math/tuple_add.c				\
			math/tuple_equal.c				\
			math/tuple_cross.c				\
			math/tuple_dot.c				\
			math/tuple_magnitude.c			\
			math/tuple_negate.c				\
			math/tuple_new.c				\
			math/tuple_normalize.c			\
			math/tuple_print.c				\
			math/tuple_scalar.c				\
			math/tuple_substract.c			\
			math/tuple_tocolor.c			\
			world/pre_compute.c				\
			world/world.c

SRC_BONUS	:=	main.c						\
			test.c							\
			scenes.c						\
			camera/camera.c					\
			camera/view_transform.c			\
			colors/colors.c					\
			colors/get_emission.c			\
			colors/more_colors.c			\
			light/light.c					\
			light/shading.c					\
			mlx/init_mlx.c					\
			mlx/key_manager.c				\
			mlx/mlx_clear.c					\
			mlx/mlx_pixel_put.c				\
			mlx/pixel_at.c					\
			shapes/cube.c					\
			pattern/checker.c				\
			pattern/cubical_map.c			\
			pattern/cylindrical_map.c		\
			pattern/gradient.c				\
			pattern/planar_map.c			\
			pattern/pattern.c				\
			pattern/radial.c				\
			pattern/ring.c					\
			pattern/stripe.c				\
			pattern/uv_mapping.c			\
			pattern/texture_map.c			\
			ray/ray_transform.c				\
			ray/cache_ray.c					\
			ray/ray.c						\
			ray/reflect.c					\
			ray/refract.c					\
			ray/schlick.c					\
			render/path_tracing.c			\
			render/per_pixel.c				\
			render/render.c					\
			shapes/cone.c					\
			shapes/cylinder_intersect.c		\
			shapes/cylinder.c				\
			shapes/glass_sphere.c			\
			shapes/material.c				\
			shapes/normal.c					\
			shapes/plane.c					\
			shapes/sphere.c					\
			shapes/triangle.c				\
			math/matrix/rotate.c			\
			math/matrix/transform.c			\
			math/matrix/degrees_to_radians.c\
			math/matrix/matrix_cmp.c		\
			math/matrix/matrix_determinant.c\
			math/matrix/matrix_inverse.c	\
			math/matrix/matrix_multiply.c	\
			math/matrix/matrix_print.c		\
			math/matrix/matrix_transpose.c	\
			math/matrix/matrix.c			\
			math/color_new.c				\
			math/float_swap.c				\
			math/hadamard_product.c			\
			math/interpolation.c			\
			math/random.c					\
			math/time.c						\
			math/tuple_add.c				\
			math/tuple_equal.c				\
			math/tuple_cross.c				\
			math/tuple_dot.c				\
			math/tuple_magnitude.c			\
			math/tuple_negate.c				\
			math/tuple_new.c				\
			math/tuple_normalize.c			\
			math/tuple_print.c				\
			math/tuple_scalar.c				\
			math/tuple_substract.c			\
			math/tuple_tocolor.c			\
			world/pre_compute.c				\
			world/world.c

SRC_DIR	:=	src
BUILD	:=	.build

SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ 	:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))
DEP		:=	$(OBJ:.o=.d)

LIBFT	:=	libft/libft.a
MLX		:=	mlx_linux/libmlx_Linux.a
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -MMD -MP -Iinclude -Ilibft/include -Imlx_linux -g
MATH	:=	-lm

all: create_dir $(NAME)

create_dir: | $(BUILD)

print:
	@echo $(OBJ)

$(BUILD):
	@mkdir -p $(BUILD)

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz -o $(NAME) $(LIBFT) $(MATH)

$(BUILD)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1;32%sm\tCompiled: $(<F)\033[0m\n";

$(MLX):
	@$(MAKE) -C mlx_linux

$(LIBFT):
	@$(MAKE) --no-print-directory -C libft

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

-include $(DEP)

.PHONY: all clean fclean re create_dir

